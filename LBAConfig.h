#ifndef LBACONFIG_H
#define LBACONFIG_H

#include <vector>
#include <string>

class LBAConfig {
private:
    int numberOfServers;
    int numberOfTasks;
    std::string algorithm;
    std::vector<int> latencies;
    std::vector<int> capabilities;
    bool range;
    
public:
    LBAConfig(int numberOfServers, int numberOfTasks, std::string algorithmn, const std::vector<int>& latencies, 
              const std::vector<int>& capabilities, bool r);

    int getNumberOfServers();
    bool setNumberOfServers(int value);
    bool isRange() { return range; }

    int getNumberOfTasks();
    bool setNumberOfTasks(int value);

    std::vector<int>& getLatencies();
    bool setLatencies(const std::vector<int>& value);

    std::vector<int>& getCapabilities();
    bool setCapabilities(const std::vector<int>& value);

    std::string getAlgorithm();

    bool read();
};

#endif // LBACONFIG_H
