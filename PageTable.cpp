#include "PageTable.h"

//Default constructor
PageTable::PageTable(void) {
    //Initialize an invalid page table entry to return if needed
    invalid.frame = 0;
    invalid.ref = false;
    invalid.dirty = false;
    invalid.valid = false;
}

//Print the page table
void PageTable::Print(void) {
    std::cout << std::endl;
    std::cout << "Page Table:" << std::endl;
    std::cout << "-------------------------" << std::endl;
}

bool PageTable::EntryExists(const uint16_t page) {
    //Return true if the page entry exists AND is valid
    if(table.count(page)) {
        if(table[page].valid) {
            return true;
        }
    }

    return false;
}

void PageTable::AddEntry(const uint16_t page, PageTableEntry & entry) {
    //Set the valid bit
    entry.valid = true;

    //Store the entry in the page table
    table[page] = entry;
}

void PageTable::RemoveEntry(const uint16_t page) {
    table.erase(page);
}

PageTableEntry & PageTable::GetEntry(const uint16_t page) {
    //Returns the entry associated with the page, if it exists
    if(table.count(page)) {
        return table[page];
    } else {
        return invalid;
    }
}
