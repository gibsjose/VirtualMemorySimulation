#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
#include <vector>
#include <queue>

const size_t MEM_SIZE = 16 * 1024;  //16kB of Physical Memory

class Memory {
public:
    Memory(void) {
        memory.clear();
    }

    //Reference a frame
    void Reference(uint16_t);

private:
    //Check if the frame is currently in memory
    bool InMemory(uint16_t);

    //Check if the frame is in the free frame list
    bool InFree(uint16_t);

    //Requested frame is not in memory or free list --> Page Fault
    void PageFault(uint16_t);

    std::vector<uint16_t> memory;       //List of frames in memory
    std::queue<uint16_t> free;          //List of 'free' frames
};

#endif//MEMORY_H
