#ifndef LBA_RESULTS_H
#define LBA_RESULTS_H

#include "Logger.h"
#include <vector>

class LBAResults {
private:
    int totalResponseTime;
    std::string algorithmn;
    std::vector<int> taskDistrbution;
    std::vector<int> serverCapabilities;
    std::vector<int> probeLatencies;
public:
    LBAResults() {};
    LBAResults(int totalTime, std::string algo, std::vector<int>& distribution,
               std::vector<int>& capabilities, std::vector<int>& latencies);
    bool printResults();
};

#endif // LB_TWO_CHOICE_H