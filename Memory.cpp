#include "Memory.h"

//Return a free frame
bool Memory::GetFrameNumber(uint16_t * frame) {
    //Scan through the free
}

//Reference a frame
void Reference(Process & process, uint16_t page); {

    //Check to see if the process already has an entry in it's page table
    if(process.GetPageTable().EntryExists(page)) {
        //Get frame number
        uint16_t frame = process.GetPageTable().GetEntry(page).frame;

        //Check to see if it is already in RAM or if it is in the free frame list
        if(InMemory(frame)) {
            //...nothing to do...
            std::cout << "Frame " << frame << " already in RAM" << std::endl;
            return;
        }

        else if(InFree(frame)) {
            std::cout << "Frame " << frame << " in free frame list" << std::endl;
            return;
        }

        //Bad... if the entry exists it should always either be in the free frame list or in RAM
        else {
            std::cerr << "Frame " << frame << ": something bad has happened..." << std::endl;
            return;
        }
    }

    //Process does NOT have an entry for this page: PAGE FAULT
    else {
        std::cout << "Page fault for page " << page << std::endl;
        process.PageFault();

        //Add an entry
        PageTableEntry entry;

        //Check if there are any free frames
        if(AreFreeFrames()) {
            entry.frame = GetFreeFrame();
            entry.ref = true;
            entry.dirty = false;

            process.GetPageTable().AddEntry(page, entry);
        }

        //No free frames!
        //Must implement LRU to select a victim...
        else {
            //Find a victim, remove it's entry from the page table (set entry.valid = false)
            //@TODO SelectVictim will call: process.GetPageTable().RemoveEntry(victimPage); <-- victimPage is whichever
            // page the LRU algorithm decides to boot off
            //
            //@TODO Isn't this supposed to be global??? Will need to know ALL processes, or store the process in
            // the ram set, so I can then have access to its page table to remove entries...
            entry.frame = SelectVictim(process);
            entry.ref = true;
            entry.dirty = false;

            process.GetPageTable().AddEntry(page, entry)
        }
    }
}

//Select a victim process using the LRU algorithm and return its frame number
// to be used by another page
uint16_t Memory::SelectVictim(Process & process) {
    //@TODO...
    return 0;
}

//'Moves' a frame from 'available' (already erased...) into RAM
void Memory::AvailableToRAM(const uint16_t frame) {
    //Make sure it does not exist in the available list
    if(available.count(frame)) {
        available.erase(available.find(frame));
    }

    ram.insert(frame);
}

//Returns whether or not there are any available frames
bool Memory::AreFreeFrames(void) {
    return !available.empty();
}

//Return a free frame and remove it from the 'available' set
uint16_t Memory::GetFreeFrame(void) {
    if(available.empty()) {
        std::cerr << "Error: GetFreeFrame: No available frames" << std::endl;
        return INVALID_FRAME;
    }

    //Get and remove the first available frame
    uint16_t frame = *(available.begin());
    available.erase(available.begin());

    return frame;
}

//Check if the frame is currently in memory
bool Memory::InRAM(uint16_t frame) {
    return ram.count(frame);
}

//Check if the frame is in the free frame list
bool Memory::InFreeFrameList(uint16_t frame) {
    return free.count(frame);
}
