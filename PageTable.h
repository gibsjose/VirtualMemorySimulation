#ifndef PAGETABLE_H
#define PAGETABLE_H

#include <iostream>
#include <map>

//Page Table Map:
//    Page Number (KEY) --> Frame Number (VALUE)
typedef std::map<uint16_t, uint16_t> PageTableMap_t;
typedef std::pair<uint16_t, uint16_t> PageTableEntry_t;

class PageTable {
public:
    PageTable(void) {}

    void Print(void);
    void AddEntry(uint16_t, uint16_t);
    uint16_t GetFrameNumber(uint16_t);
private:
    PageTableMap_t table;
};

#endif//PAGETABLE_H
