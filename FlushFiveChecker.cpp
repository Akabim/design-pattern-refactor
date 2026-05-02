#include "FlushFiveChecker.h"
#include <map>

std::string FlushFiveChecker::checkHand(const std::vector<Card>& cards) {
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

    // Check for 5 cards same suit AND 5 cards same rank
    bool hasFiveOfSameSuit = false;
    bool hasFiveOfSameRank = false;

    for (const auto& pair : suitCount) {
        if (pair.second >= 5) hasFiveOfSameSuit = true;
    }

    for (const auto& pair : rankCount) {
        if (pair.second >= 5) hasFiveOfSameRank = true;
    }

    if (hasFiveOfSameSuit && hasFiveOfSameRank) {
        return "Flush Five";
    }

    return passToNext(cards);
}
