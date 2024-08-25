#include "LBASimulator.h"
#include "Logger.h"
#include "LBAFactory.h"
#include <iostream>

LBASimulator::LBASimulator(const LBAConfig& config, const std::string& helpString)
    : config(config), helpString(helpString) {}

bool LBASimulator::printHelp() {
    // Print help string (Placeholder)
    std::cout << helpString << std::endl;
    return true;
}

bool LBASimulator::run() {
    // Start the simulation (Placeholder)
    Logger& logger = Logger::getLogger();
    logger.log(Logger::LogLevel::DEBUG, "LBASimulator::run: Running the simulation");
    auto algo = config.getAlgorithm();
    // If the algorithm type is ALL, create all the algorithms as the same data set needs to be run on all the algorithms
    if (algo == "ALL") {
        logger.log(Logger::LogLevel::DEBUG, "Creating all the algorithms for execution \n ");
        auto algoPTC = LBAFactory::create("PTC", config);
        auto algoPTCRR = LBAFactory::create("PTCRR", config);
        auto algoPTCB = LBAFactory::create("PTCB", config);
        bool ret = algoPTC->execute();
        logger.log(Logger::LogLevel::DEBUG, "PTC Execution returned %d\n ", ret);
        algorithms.push_back(algoPTC);
        ret = algoPTCRR->execute();
        logger.log(Logger::LogLevel::DEBUG, "PTCRR Execution returned %d\n ", ret);
        algorithms.push_back(algoPTCRR);
        ret = algoPTCB->execute();
        logger.log(Logger::LogLevel::DEBUG, "PTCB Execution returned %d\n ", ret);
        algorithms.push_back(algoPTCB);
    } else {
        auto algorithm = LBAFactory::create(algo, config);
        if (algorithm) {
            // Use the algorithm
            bool success = algorithm->execute();
            logger.log(Logger::LogLevel::DEBUG, "Execution success %d\n ", success);
            // store the algorithm object
            algorithms.push_back(algorithm);
        } else {
            logger.log(Logger::LogLevel::ERROR, "Unknown algorithm type! \n ");
        }
    }
    
    return true;
}

bool LBASimulator::printResults() {
    Logger& logger = Logger::getLogger();
    logger.log(Logger::LogLevel::DEBUG, "LBASimulator::printResults: Printing results of the simulation");
    for (auto a: algorithms) {
        a->getResult().printResults();
        std::cout << std::endl;
    }
    
    return true;
}
