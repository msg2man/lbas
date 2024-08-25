#include "LBAFactory.h"
#include "LBTwoChoice.h"
#include "LBTwoChoiceRR.h"
#include "LBTwoChoiceBias.h"
#include "Logger.h"

std::shared_ptr<LBAlgorithm> LBAFactory::create(const std::string &algorithmType, LBAConfig &config) {
    if (algorithmType == "PTC") {
        // Return an instance of LBTwoChoice for the Power of Two Choices algorithm
        Logger& logger = Logger::getLogger();
        logger.log(Logger::LogLevel::DEBUG, "LBAFactory::create: Creating algorithm instance for %s ", algorithmType.c_str());
        return std::make_shared<LBTwoChoice>(config);
    } else if (algorithmType == "PTCRR") {
        // Return an instance of LBTwoChoiceRR for the Power of Two Choices with Round Robin algorithm
        Logger& logger = Logger::getLogger();
        logger.log(Logger::LogLevel::DEBUG, "LBAFactory::create: Creating algorithm instance for %s ", algorithmType.c_str());
        return std::make_shared<LBTwoChoiceRR>(config);
    } else if (algorithmType == "PTCB") {
        // Return an instance of LBTwoChoiceBias for the Power of Two Choices with Bias algorithm
        Logger& logger = Logger::getLogger();
        logger.log(Logger::LogLevel::DEBUG, "LBAFactory::create: Creating algorithm instance for %s ", algorithmType.c_str());
        return std::make_shared<LBTwoChoiceBias>(config);
    }
    // Add other algorithm types here if needed
    else {
        // Handle unknown algorithm types
        return nullptr;
    }
}
