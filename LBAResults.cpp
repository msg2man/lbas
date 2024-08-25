#include "LBAResults.h"
#include <iostream>

LBAResults::LBAResults(int totalTime, std::string algo, std::vector<int>& distribution,
                       std::vector<int>& capabilities, std::vector<int>& latencies) :
                       totalResponseTime(totalTime), algorithmn(algo), taskDistrbution(distribution),
                       serverCapabilities(capabilities), probeLatencies(latencies) {

}

bool LBAResults::printResults() {
    // Print the results
    std::cout <<"Algorithm                        : " << algorithmn << std::endl;
    std::cout <<"Total System Response Time       : " << totalResponseTime << std::endl;
    std::cout <<"Tasks Distribution across Servers: ";
    for (auto e : taskDistrbution) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
    std::cout <<"Server Capabilities              : ";
    for (auto e : serverCapabilities) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
    std::cout <<"Probe Message Latencies          : ";
    for (auto e : probeLatencies) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
    return true;
}