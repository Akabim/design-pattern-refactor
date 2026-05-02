#include "FlushHouseChecker.h"
#include <map>

std::string FlushHouseChecker::checkHand(const std::vector<Card>& cards) {
    if (cards.size() < 5) {
        return passToNext(cards);
    }

    // Count suits
    std::map<Card::Suit, int> suitCount;
    for (const auto& card : cards) {
        suitCount[card.getSuit()]++;
    }

    // Count ranks
    std::map<Card::Rank, int> rankCount;
    for (const auto& card : cards) {
        rankCount[card.getRank()]++;
    }

    // Check for full house (3 of a kind + 2 of a kind)
    bool hasThreeOfAKind = false;
    bool hasPair = false;

    for (const auto& pair : rankCount) {
        if (pair.second >= 3) hasThreeOfAKind = true;
        if (pair.second >= 2) hasPair = true;
    }

    // Check for flush (5 of same suit)
    bool hasFlush = false;
    for (const auto& pair : suitCount) {
        if (pair.second >= 5) hasFlush = true;
    }

    if (hasThreeOfAKind && hasPair && hasFlush) {
        return "Flush House";
    }

    return passToNext(cards);
}
