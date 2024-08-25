#ifndef LBAFACTORY_H
#define LBAFACTORY_H

#include <string>
#include <memory>
#include "LBAlgorithm.h"
#include "LBAConfig.h"

class LBAFactory {
public:
    static std::shared_ptr<LBAlgorithm> create(const std::string &algorithmType, LBAConfig &config);
};

#endif // LBAFACTORY_H
