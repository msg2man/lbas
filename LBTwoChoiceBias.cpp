#include "LBTwoChoiceBias.h"
#include "Logger.h"
#include <vector>

bool LBTwoChoiceBias::execute() {
    // call base method to setup configuration for algorithm
    setConfiguration();

    // PTCB
    for (int i = 0; i <  config.getNumberOfTasks(); i++) {
        // Generate the random num from 0, number of servers -1 as 0 based numbering
        auto s1 = LBAlgorithm::generateRandomNumber(0,  config.getNumberOfServers() - 1);
        auto s2 = LBAlgorithm::generateRandomNumber(0,  config.getNumberOfServers() - 1);
        if (serverCapabilities[s1] >= serverCapabilities[s2]) {
            serverList[s1] = serverList[s1] + 1;
        } else {
            serverList[s2] = serverList[s2] + 1;
        }
    }

    auto totalTime = 0; 
    for (int i = 0; i < serverList.size(); i++) {
        if (serverList[i] > 0) {
            totalTime = (serverList[i] / serverCapabilities[i]);
        }
    }

    LBAResults res(totalTime, "PTCB", serverList, serverCapabilities, probeLatencies);
    this->result = res;

    return true;
}
