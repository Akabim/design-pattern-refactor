#include "FullHouseChecker.h"
#include <map>

std::string FullHouseChecker::checkHand(const std::vector<Card>& cards) {
    if (cards.size() < 5) {
        return passToNext(cards);
    }

    std::map<Card::Rank, int> rankCount;
    for (const auto& card : cards) {
        rankCount[card.getRank()]++;
    }

    int threes = 0;
    int twos = 0;

    for (const auto& pair : rankCount) {
        if (pair.second >= 3) {
            threes++;
        } else if (pair.second >= 2) {
            twos++;
        }
    }

    if ((threes >= 1 && twos >= 1) || (threes >= 2)) {
        return "Full House";
    }

    return passToNext(cards);
}
