#ifndef STRAIGHTFLUSHCHECKER_H
#define STRAIGHTFLUSHCHECKER_H

#include "HandChecker.h"

class StraightFlushChecker : public HandChecker {
public:
    std::string checkHand(const std::vector<Card>& cards) override;
};

#endif // STRAIGHTFLUSHCHECKER_H
