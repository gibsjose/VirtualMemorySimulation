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

        //Generate 16kB of frames
        for(int i = 0; i < MEM_SIZE; i++) {
            free.insert(i);
        }
    }

    //Return a free frame
    bool GetFreeFrame(uint16_t *);

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
    std::set<uint16_t> free;            //List of 'free' frames
};

#endif//MEMORY_H
