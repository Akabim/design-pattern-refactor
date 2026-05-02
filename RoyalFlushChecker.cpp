#include "RoyalFlushChecker.h"
#include <algorithm>
#include <set>

std::string RoyalFlushChecker::checkHand(const std::vector<Card>& cards) {
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

    // Check if cards are A, K, Q, J, 10
    std::set<Card::Rank> rankSet;
    for (const auto& card : cards) {
        rankSet.insert(card.getRank());
    }

    if (rankSet.count(Card::TEN) &&
        rankSet.count(Card::JACK) &&
        rankSet.count(Card::QUEEN) &&
        rankSet.count(Card::KING) &&
        rankSet.count(Card::ACE)) {
        return "Royal Flush";
    }

    return passToNext(cards);
}
