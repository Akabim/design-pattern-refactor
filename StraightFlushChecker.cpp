#include "StraightFlushChecker.h"
#include <algorithm>
#include <set>

std::string StraightFlushChecker::checkHand(const std::vector<Card>& cards) {
    if (cards.size() < 5) {
        return passToNext(cards);
    }

    // Check if all cards have the same suit
    bool sameSuit = true;
    for (size_t i = 1; i < cards.size(); i++) {
        if (cards[i].getSuit() != cards[0].getSuit()) {
            sameSuit = false;
            break;
        }
    }

    if (!sameSuit) {
        return passToNext(cards);
    }

    // Check if cards form a straight
    std::set<int> rankSet;
    for (const auto& card : cards) {
        rankSet.insert(static_cast<int>(card.getRank()));
    }

    if (rankSet.size() < 5) {
        return passToNext(cards);
    }

    std::vector<int> uniqueRanks(rankSet.begin(), rankSet.end());
    bool isStraight = false;
    
    // Check for normal straights
    for (size_t i = 0; i <= uniqueRanks.size() - 5; i++) {
        if (uniqueRanks[i+4] == uniqueRanks[i] + 4) {
            isStraight = true;
            break;
        }
    }

    // Check for Ace-low straight (A, 2, 3, 4, 5)
    if (!isStraight &&
        rankSet.count(static_cast<int>(Card::ACE)) &&
        rankSet.count(static_cast<int>(Card::TWO)) &&
        rankSet.count(static_cast<int>(Card::THREE)) &&
        rankSet.count(static_cast<int>(Card::FOUR)) &&
        rankSet.count(static_cast<int>(Card::FIVE))) {
        isStraight = true;
    }

    if (isStraight) {
        return "Straight Flush";
    }

    return passToNext(cards);
}
