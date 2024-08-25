#include "LBTwoChoice.h"
#include "Logger.h"
#include <vector>

bool LBTwoChoice::execute() {
    // call base method to setup configuration for algorithm
    setConfiguration();

    // PTC
    for (int i = 0; i <  config.getNumberOfTasks(); i++) {
        auto s1 = LBAlgorithm::generateRandomNumber(0, config.getNumberOfServers() - 1);
        auto s2 = LBAlgorithm::generateRandomNumber(0, config.getNumberOfServers() - 1);
        if (serverList[s1] >= serverList[s2]) {
            serverList[s2] = serverList[s2] + 1;
        } else {
            serverList[s1] = serverList[s1] + 1;
        }
    }

    // calculate the total system time - PTC
    auto totalTime = 0;
    for (int i = 0; i < serverList.size(); i++) {
        if (serverList[i] > 0) {
            totalTime = (serverList[i] / serverCapabilities[i]) * probeLatencies[i];
        } else {
            std::cout << "Server did not have any task : " << i << std::endl;
        }
    }

    LBAResults res(totalTime, "PTC", serverList, serverCapabilities, probeLatencies);
    this->result = res;
    std::cout << std::endl;

    return true;
}
