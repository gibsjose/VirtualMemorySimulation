#ifndef PAGETABLE_H
#define PAGETABLE_H

#include <iostream>
#include <unordered_map>

struct PageTableEntry {
public:
    PageTableEntry(void) : frame(0), ref(false), dirty(false), valid(true) {}

    uint16_t frame;     //Frame number
    bool ref;           //Reference 'Bit': This bit indicates that the memory has been referenced
    bool dirty;         //Dirty 'Bit': This bit indicates whether a write has been performed
    bool valid;         //Valid 'Bit': This is set to 'false' to indicate that there
                        // is no page table entry when GetEntry() is called
};

//Page Table Map:
//    Page Number (KEY) --> Page Table Entry (VALUE)
typedef std::unordered_map<uint16_t, PageTableEntry> PageTableMap_t;

class PageTable {
public:
    PageTable(void);

    void Print(void);
    bool EntryExists(const uint16_t);
    void AddEntry(const uint16_t, PageTableEntry &);
    void RemoveEntry(const uint16_t);
    PageTableEntry & GetEntry(const uint16_t);
    
private:
    PageTableMap_t table;
    PageTableEntry invalid;
};

#endif//PAGETABLE_H
