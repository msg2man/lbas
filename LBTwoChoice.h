#ifndef LB_TWO_CHOICE_H
#define LB_TWO_CHOICE_H

#include "LBAlgorithm.h"

class LBTwoChoice : public LBAlgorithm {
public:
    LBTwoChoice(LBAConfig& cfg) : LBAlgorithm(cfg) {}
    bool execute() override;
};

#endif // LB_TWO_CHOICE_H
