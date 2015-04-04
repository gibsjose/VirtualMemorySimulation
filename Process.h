#ifndef PROCESS_H
#define PROCESS_H

#include <algorithm>
#include <bitset>
#include <set>
#include <string>

#include "PCB.h"

class Process {
public:
    Process(void);
    Process(const std::string &);
    uint16_t PageAccess(const std::string &);
    const std::string & GetName(void) { return name; }
    void PageFault(void);
    void DisplayStatistics(void);
    PageTable & GetPageTable(void) { return pcb.GetPageTable(); }

private:
    uint16_t DecodePageNumber(const std::string &);
    uint16_t GetMinPageNumber(void);
    uint16_t GetMaxPageNumber(void);
    uint16_t ComputeSize(void);

    std::string name;           //Process name (i.e. "P2")
    uint16_t references;        //Number of memory references
    uint16_t pageFaults;        //Number of page faults
    uint16_t size;              //Total size in number of pages (each page is 1024 bytes)
    PCB pcb;                    //Process Control Block
    std::set<uint16_t> pages;   //Set of referenced page numbers
};

#endif//PROCESS_H
