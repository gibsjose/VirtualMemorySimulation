#ifndef SIMULATION_H
#define SIMULATION_H

//C++
#include <iostream>
#include <map>
#include <string>
#include <fstream>

//Qt
//#include <QApplication>
//#include <QPushButton>

//Project
#include "StringUtilities.h"
#include "Exception.h"
#include "Process.h"
#include "Memory.h"

typedef std::map<std::string, Process> ProcessMap_t;
typedef std::pair<std::string, Process> ProcessEntry_t;

class Simulation {
public:
    Simulation(void) {}
    void SetInputFilepath(const std::string &);
    void Run(void);
    void DisplayStatistics(void);

private:
    std::string filepath;
    ProcessMap_t processes;
    Memory memory;
};

#endif//SIMULATION_H
