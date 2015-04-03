#include "Process.h"

//Default constructor (needed for maps)
Process::Process(void) {
    name.clear();
    references = 0;
    pageFaults = 0;
    size = 0;
}

//Constructor: Set the name and generate the page table
Process::Process(const std::string & name) {
    this->name = name;
    references = 0;
    pageFaults = 0;
    size = 0;

    //GENERATE PAGE TABLE, NO COLLISIONS WITH OTHER PROCESSES... NEED TO KNOW MEMORY OR DO THIS IN SIM
}

uint16_t Process::PageAccess(const std::string & string) {
    //Decode the string into the page number
    uint16_t page = DecodePageNumber(string);

    //Add the referenced page number to the set
    pages.insert(page);

    //Determine the range of the page set (this is the size...)
    size = ComputeSize();

    //Increment number of references
    references++;

    //Determine which frame corresponds to the page number
    uint16_t frame = pcb.GetPageTable().GetFrameNumber(page);

    //Return the frame number
    return frame;
}

//Display process statistics
void Process::DisplayStatistics(void) {
    std::cout << std::endl;
    std::cout << "Process: \"" << name << "\"" << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout << "Memory References: " << references << std::endl;
    std::cout << "Size in Pages: " << size << std::endl;
    std::cout << "Fault Rate: " << (pageFaults / references) * 100 << "%" << std::endl;
}

//Decodes a 6-character binary representation of a page number into a decimal number
uint16_t Process::DecodePageNumber(const std::string & string) {
    //Create a bitset from the string
    std::bitset<6> bitset(string);

    //Return and cast the integer representation of the bitset
    return (uint16_t)bitset.to_ulong();
}

//Get the number of the lowest known page for the process (actual lowest is always 0)
uint16_t Process::GetMinPageNumber(void) {
    return *(min_element(pages.begin(), pages.end()));
}

//Get the number of the highest known page for the process
uint16_t Process::GetMaxPageNumber(void) {
    return *(max_element(pages.begin(), pages.end()));
}

uint16_t Process::ComputeSize(void) {
    return GetMaxPageNumber();
}
