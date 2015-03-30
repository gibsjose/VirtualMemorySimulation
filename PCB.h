#ifndef PCB_H
#define PCB_H

#include "PageTable.h"

class PCB {
public:
    PCB(void) {}
    PageTable & GetPageTable(void) { return pageTable; }

private:
    PageTable pageTable;
};

#endif//PCB_H
