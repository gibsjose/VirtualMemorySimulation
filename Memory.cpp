#include "Memory.h"

//Reference a frame
void Memory::Reference(uint16_t frame) {
    //Check if in memory
    if(InMemory(frame)) {
        std::cout << "Frame " << frame << " already in RAM" << std::endl;
        return;
    }

    //Check if in free frame list (mark as referenced)
    else if(InFree(frame)) {
        std::cout << "Frame " << frame << " in free frame list" << std::endl;
        return;
    }

    //Page Fault
    else {
        std::cout << "Page fault for frame " << frame << std::endl;
        PageFault(frame);
        return;
    }
}

//Check if the frame is currently in memory
bool Memory::InMemory(uint16_t frame) {
    return false;
}

//Check if the frame is in the free frame list
bool Memory::InFree(uint16_t frame) {
    return false;
}

//Requested frame is not in memory or free list --> Page Fault
void Memory::PageFault(uint16_t frame) {
    //...
}
