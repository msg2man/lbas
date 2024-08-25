#ifndef LB_TWO_CHOICE_BIAS_H
#define LB_TWO_CHOICE_BIAS_H

#include "LBAlgorithm.h"

class LBTwoChoiceBias : public LBAlgorithm {
public:
    LBTwoChoiceBias(LBAConfig& cfg) : LBAlgorithm(cfg) {}
    bool execute() override;
};

#endif // LB_TWO_CHOICE_RR_H