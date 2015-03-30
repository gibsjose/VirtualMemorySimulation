#include "PageTable.h"

//Print the page table
void PageTable::Print(void) {
    std::cout << std::endl;
    std::cout << "Page Table:" << std::endl;
    std::cout << "-------------------------" << std::endl;

    for(PageTableMap_t::iterator it = table.begin(); it != table.end(); ++it) {
        std::cout << "Page " << it->first << " --> Frame " << it->second << std::endl;
    }
}

//Add a page/frame number pair to the map
void PageTable::AddEntry(uint16_t page, uint16_t frame) {
    table[page] = frame;
}

//Return the frame number associated with the page
uint16_t PageTable::GetFrameNumber(uint16_t page) {
    return table[page];
}
