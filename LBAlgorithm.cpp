#include "LBAlgorithm.h"
#include "Logger.h"

// Definition of the global variable
bool ALL_ALGORITHM = false;

// Static member definitions
std::vector<int> LBAlgorithm::probeLatencies;
std::vector<int> LBAlgorithm::serverCapabilities;
std::vector<int> LBAlgorithm::serverList;

bool LBAlgorithm::setConfiguration() {
    if (ALL_ALGORITHM == true) {
        // Initialize server list
        serverList.clear();
        for (int i = 0; i < config.getNumberOfServers(); i++) {
            serverList.push_back(0);
        }
        return true;
    }

    auto latencies = config.getLatencies();
    auto servers = config.getNumberOfServers();
    auto capabilities = config.getCapabilities();

    // Initialize server list
    serverList.clear();
    for (int i = 0; i < servers; i++) {
        serverList.push_back(0);
    }

    // Set probe latencies
    probeLatencies.clear();
    // for (int i = 0; i < servers; i++) {
    //     int min = latencies[0];
    //     int max = latencies[1];
    //     int randomNum = LBAlgorithm::generateRandomNumber(min, max);
    //     probeLatencies.push_back(randomNum);
    // }

    if (config.isRange() == true) {
        for (int i = 0; i < servers; i++) {
            int min = latencies[0];
            int max = latencies[1];
            int randomNum = LBAlgorithm::generateRandomNumber(min, max);
            probeLatencies.push_back(randomNum);
        }
    } else {
        int min = latencies[0];
        int max = latencies[1];
        for (int i = 0; i < servers/2; i++) {
            probeLatencies.push_back(min);
        }
        for (int i = servers/2; i < servers; i++) {
            probeLatencies.push_back(max);
        }
    }

    // Log probe latencies
    Logger& logger = Logger::getLogger();
    logger.log(Logger::LogLevel::DEBUG, "LBAlgorithm: Probe latencies are:");
    for (auto l : probeLatencies) {
        logger.log(Logger::LogLevel::DEBUG, std::to_string(l));
    }

    // Set server capabilities
    serverCapabilities.clear();
    if (config.isRange() == true) {
        logger.log(Logger::LogLevel::DEBUG, "Using range capabilities");
        for (int i = 0; i < servers; i++) {
            int min = capabilities[0];
            int max = capabilities[1];
            int randomNum = LBAlgorithm::generateRandomNumber(min, max);
            serverCapabilities.push_back(randomNum);
        }
    } else {
        logger.log(Logger::LogLevel::DEBUG, "Using non range capabilities");
        int min = capabilities[0];
        int max = capabilities[1];
        for (int i = 0; i < servers/2; i++) {
            serverCapabilities.push_back(min);
        }
        for (int i = servers/2; i < servers; i++) {
            serverCapabilities.push_back(max);
        }
    }

    // Log server capabilities
    logger.log(Logger::LogLevel::DEBUG, "LBAlgorithm: Server Capabilities are:");
    for (auto l : serverCapabilities) {
        logger.log(Logger::LogLevel::DEBUG, std::to_string(l));
    }

    if (config.getAlgorithm() == "ALL")
        ALL_ALGORITHM = true;

    return true;
}
