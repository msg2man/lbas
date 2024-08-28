#include "LBAConfig.h"
#include "Logger.h"
#include <iostream>

LBAConfig::LBAConfig(int numberOfServers, int numberOfTasks, std::string algo, const std::vector<int>& latencies, const std::vector<int>& capabilities, bool r)
    : numberOfServers(numberOfServers), numberOfTasks(numberOfTasks), algorithm(algo), latencies(latencies), capabilities(capabilities), range(r) {

    Logger& logger = Logger::getLogger();
    for (auto e: latencies) {
        logger.log(Logger::LogLevel::DEBUG, "LBAConfig: Latencies: %d ", e);
    }

    for (auto e: capabilities) {
        logger.log(Logger::LogLevel::DEBUG, "LBACofig: Capabilities: %d ", e);
    }

    logger.log(Logger::LogLevel::DEBUG, "LBAConfig: Algorithm : %s ", this->algorithm.c_str());

}

int LBAConfig::getNumberOfServers(){
    return numberOfServers;
}

bool LBAConfig::setNumberOfServers(int value) {
    numberOfServers = value;
    return true;
}

int LBAConfig::getNumberOfTasks() {
    return numberOfTasks;
}

bool LBAConfig::setNumberOfTasks(int value) {
    numberOfTasks = value;
    return true;
}

std::vector<int>& LBAConfig::getLatencies() {
    return latencies;
}

bool LBAConfig::setLatencies(const std::vector<int>& value) {
    latencies = value;
    return true;
}

std::vector<int>& LBAConfig::getCapabilities() {
    return capabilities;
}

bool LBAConfig::setCapabilities(const std::vector<int>& value) {
    capabilities = value;
    return true;
}

std::string LBAConfig::getAlgorithm() {
    return algorithm;
}
