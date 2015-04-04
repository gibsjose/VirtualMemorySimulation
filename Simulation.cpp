#include "Simulation.h"

int main(int argc, char **argv) {
    Simulation simulation;

    std::cout << "Virtual Memory Simulation" << std::endl;

    //Get the input file from the user
    std::string filepath;
    std::cout << "Input file: ";
    std::cin >> filepath;

    //Remove whitespace/newlines
    StringUtilities::Trim(filepath);

    simulation.SetInputFilepath(filepath);
    simulation.Run();

    std::cout << "Simulation Complete:" << std::endl;

    simulation.DisplayStatistics();
}

//Set the input filepath
void Simulation::SetInputFilepath(const std::string & filepath) {
    this->filepath = filepath;
}

//Run the simulation
void Simulation::Run(void) {
    //Read in the input file
    std::ifstream file(filepath);
    std::string line;
    std::vector<std::string> values;
    std::string name;
    std::string pageString;

    unsigned long lineNumber = 0;
    uint16_t frame;

    if(!file.is_open()) {
        std::cerr << "File \"" << filepath << "\" could not be opened. Check to see if it exists" << std::endl;
        exit(-1);
    }

    //Iterate over each line of the file
    while(std::getline(file, line)) {

        //Skip blank lines
        if(line.empty()) {
            continue;
        }

        values = StringUtilities::SplitString(line, ":\t");

        if(values.size() < 2) {
            std::cerr << "Error: Line " << lineNumber << ": \"" << line << "\" does not follow format of \"{NAME}:<TAB>{Page #}\"" << std::endl;
            exit(-1);
        }

        name = values.at(0);
        pageString = values.at(1);

        //New process: Add it to the map
        if(!processes.count(name)) {
            Process process(name);
            processes[name] = process;
        }

        //Get the process object
        Process & process = processes.find(name)->second;
        uint16_t page = process.PageAccess(pageString);

        //Reference the process page in memory
        // This could result in one of three things:
        // 1. There is already a frame associated with the page number, and it is already in memory
        // 2. There is already a frame associated with the page number, and it is on the free frame list
        // 3. There is no frame associated with this page number --> Page fault: Assign it a page number and bring frame into
        //     memory
        memory.Reference(process, page);

        //Increment line number
        lineNumber++;
    }
}

void Simulation::DisplayStatistics(void) {
    //Show statistics for each process
    for(ProcessMap_t::iterator it = processes.begin(); it != processes.end(); ++it) {
        it->second.DisplayStatistics();
    }
}
