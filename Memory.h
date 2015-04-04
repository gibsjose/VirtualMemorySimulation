#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
#include <set>

#include "Process.h"

const size_t MEM_SIZE = 16 * 1024;                      //16kB of Physical Memory = 16 Frames
const size_t FRAME_SIZE = 1024;                         //1kB Frame/Page Size
const size_t INVALID_FRAME = (MEM_SIZE / FRAME_SIZE);   //Index of an invalid frame (valid indices are 0 -> INVALID_FRAME - 1)

class Memory {
public:
    Memory(void) {
        ram.clear();
        available.clear();
        free.clear();

        //Generate 16 available frames
        for(int i = 0; i < (MEM_SIZE / FRAME_SIZE); i++) {
            available.insert(i);
        }
    }

    //Reference a frame
    void Reference(Process &, uint16_t);

private:
    //Selects a victim using the LRU algorithm
    uint16_t Memory::SelectVictim(Process &);

    //'Moves' a frame from the available set to the ram set
    void Memory::AvailableToRAM(const uint16_t);

    //Returns whether or not there are any available frames
    bool AreFreeFrames(void);

    //Return a free frame and remove it from the available set
    uint16_t GetFreeFrame(void);

    //Check if the frame is currently in memory
    bool InRAM(uint16_t);

    //Check if the frame is in the free frame list
    bool InFreeFrameList(uint16_t);

    std::set<uint16_t> ram;         //Frames actually loaded into RAM
    std::set<uint16_t> available;   //Frames available to be loaded into RAM
    std::set<uint16_t> free;        //Free frame list
};

#endif//MEMORY_H
