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
    std::string page;

    unsigned long lineNumber = 0;
    uint16_t frame;

    //Iterate over each line of the file
    while(std::getline(file, line)) {

        //Skip blank lines
        if(line.empty()) {
            continue;
        }

        values = StringUtilities::SplitString(line, ": ");

        if(values.size() < 2) {
            std::cerr << "Error: Line " << lineNumber << ": \"" << line << "\" does not follow format of \"{NAME}: {Page #}\"" << std::endl;
            exit(-1);
        }

        name = values.at(0);
        page = values.at(1);

        //New process: Add it to the map
        if(!processes.count(name)) {
            Process process(name);
            processes[name] = process;
        }

        //Register a page access on the process and get the corresponding frame number
        Process & process = processes.find(name)->second;
        frame = process.PageAccess(page);

        //Reference the frame in memory
        memory.Reference(frame);

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
