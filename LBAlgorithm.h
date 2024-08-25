#ifndef LBALGORITHM_H
#define LBALGORITHM_H

#include "LBAConfig.h"
#include "LBAResults.h"
#include <random>

extern bool ALL_ALGORITHM;

class LBAlgorithm {
protected:
    LBAConfig& config;
    static std::vector<int> probeLatencies;
    static std::vector<int> serverCapabilities;
    static std::vector<int> serverList;
    LBAResults result;

public:
    LBAlgorithm(LBAConfig& cfg) : config(cfg) {}
    virtual ~LBAlgorithm() = default;
    virtual bool execute() = 0; // Pure virtual method
    static int generateRandomNumber(int min, int max) {
        // Create a random device and seed the Mersenne Twister engine with it
        std::random_device rd;
        std::mt19937 mt(rd());

        // Define the range of the random number
        std::uniform_int_distribution<int> dist(min, max);

        // Generate and return the random number
        return dist(mt);
    }
    // set the configuration to be used by LB algorithms
    bool setConfiguration();
    LBAResults getResult() { return result; }
};

#endif // LBALGORITHM_H
