#ifndef LBASIMULATOR_H
#define LBASIMULATOR_H

#include <string>
#include <memory>
#include "LBAConfig.h"
#include "LBAlgorithm.h"

class LBASimulator {
private:
    LBAConfig config;
    std::string helpString;
    std::vector<std::shared_ptr<LBAlgorithm>> algorithms;

public:
    LBASimulator(const LBAConfig& config, const std::string& helpString);

    bool printHelp();
    bool run();
    bool printResults();
};

#endif // LBASIMULATOR_H
