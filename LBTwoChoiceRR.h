#ifndef LB_TWO_CHOICE_RR_H
#define LB_TWO_CHOICE_RR_H

#include "LBAlgorithm.h"

class LBTwoChoiceRR : public LBAlgorithm {
public:
    LBTwoChoiceRR(LBAConfig& cfg) : LBAlgorithm(cfg) {}
    bool execute() override;
};

#endif // LB_TWO_CHOICE_RR_H