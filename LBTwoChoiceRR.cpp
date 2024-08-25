#include "LBTwoChoiceRR.h"
#include "Logger.h"
#include <vector>

bool LBTwoChoiceRR::execute() {
    // call base method to setup configuration for algorithm
    setConfiguration();

    auto rrIndex = 0;
    for (int i = 0; i <  config.getNumberOfTasks(); i++) {
        auto s1 = LBAlgorithm::generateRandomNumber(0, config.getNumberOfServers() - 1);
        int s2;
        if (rrIndex < serverList.size()) {
            s2 = rrIndex;
            rrIndex++;
        } else {
            rrIndex = 0;
            s2 = rrIndex;
            rrIndex++;
        }
        if (serverList[s1] <= serverList[s2]) {
            serverList[s1] = serverList[s1] + 1;
        } else {
            serverList[s2] = serverList[s2] + 1;
        }
    }

    // calculate the total system time - PTCRR
    auto totalTime = 0;
    for (int i = 0; i < serverList.size(); i++) {
        if (serverList[i] > 0) {
            totalTime = (serverList[i] / serverCapabilities[i]) * probeLatencies[i];
        } else {
            std::cout << "Server did not have any task : " << i << std::endl;
        }
    }
    
    LBAResults res(totalTime, "PTCRR", serverList, serverCapabilities, probeLatencies);
    this->result = res;

    return true;
}
