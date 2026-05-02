#include "StraightFlushChecker.h"
#include <algorithm>

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
    std::vector<Card::Rank> ranks;
    for (const auto& card : cards) {
        ranks.push_back(card.getRank());
    }
    std::sort(ranks.begin(), ranks.end());

    // Check for consecutive sequence
    bool isStraight = true;
    if (ranks.size() >= 5) {
        for (size_t i = 1; i < 5; i++) {
            if (ranks[i] != ranks[i-1] + 1) {
                isStraight = false;
                break;
            }
        }
    }

    if (isStraight && ranks.size() >= 5) {
        return "Straight Flush";
    }

    return passToNext(cards);
}
