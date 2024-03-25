#include "inputFile.h"
#include "fcfs.h"
#include <iostream>
#include <ctime> // For generating unique filename based on timestamp

int main()
{
    // Input processes
    std::vector<Process *> processes = inputProcesses();

    // Ask user whether to save metrics to a file
    char saveToFileInput;
    std::cout << "Do you want to save process metrics to a file? (y/n): ";
    std::cin >> saveToFileInput;

    bool saveToFile = (saveToFileInput == 'y' || saveToFileInput == 'Y');

    // Generate unique filename based on current timestamp
    std::time_t currentTime = std::time(nullptr);
    std::string filename = "metrics_" + std::to_string(currentTime) + ".txt";

    // Schedule processes using FCFS algorithm
    scheduleFCFS(processes, saveToFile, filename);

    // Clean up memory
    for (auto &process : processes)
    {
        delete process;
    }

    return 0;
}
