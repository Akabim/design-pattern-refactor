#include <iostream>
#include <vector>
#include "Card.h"
#include "HandChecker.h"
#include "RoyalFlushChecker.h"
#include "StraightFlushChecker.h"
#include "FiveOfAKindChecker.h"
#include "FlushFiveChecker.h"
#include "FlushHouseChecker.h"
#include "FourOfAKindChecker.h"
#include "FullHouseChecker.h"
#include "FlushChecker.h"
#include "StraightChecker.h"
#include "ThreeOfAKindChecker.h"
#include "TwoPairChecker.h"
#include "PairChecker.h"
#include "HighCardChecker.h"

int main() {
    // Initialize chain of responsibility in order from highest to lowest hand
    // Balatro Rank: Flush Five > Flush House > Five of a Kind > Straight Flush > Four of a Kind > Full House > Flush > Straight > Three of a Kind > Two Pair > Pair > High Card
    
    RoyalFlushChecker royalFlushChecker;
    StraightFlushChecker straightFlushChecker;
    FlushFiveChecker flushFiveChecker;
    FlushHouseChecker flushHouseChecker;
    FiveOfAKindChecker fiveOfAKindChecker;
    FourOfAKindChecker fourOfAKindChecker;
    FullHouseChecker fullHouseChecker;
    FlushChecker flushChecker;
    StraightChecker straightChecker;
    ThreeOfAKindChecker threeOfAKindChecker;
    TwoPairChecker twoPairChecker;
    PairChecker pairChecker;
    HighCardChecker highCardChecker;

    // Set up the chain
    royalFlushChecker.setNextChecker(&straightFlushChecker);
    straightFlushChecker.setNextChecker(&flushFiveChecker);
    flushFiveChecker.setNextChecker(&flushHouseChecker);
    flushHouseChecker.setNextChecker(&fiveOfAKindChecker);
    fiveOfAKindChecker.setNextChecker(&fourOfAKindChecker);
    fourOfAKindChecker.setNextChecker(&fullHouseChecker);
    fullHouseChecker.setNextChecker(&flushChecker);
    flushChecker.setNextChecker(&straightChecker);
    straightChecker.setNextChecker(&threeOfAKindChecker);
    threeOfAKindChecker.setNextChecker(&twoPairChecker);
    twoPairChecker.setNextChecker(&pairChecker);
    pairChecker.setNextChecker(&highCardChecker);

    std::cout << "=== Balatro Hand Checker - Chain of Responsibility Pattern ===" << std::endl;
    std::cout << std::endl;

    // Test cases
    std::cout << "=== Manual Test Cases ===" << std::endl;
    std::cout << std::endl;

    // Test: Ace-low Straight
    std::cout << "Test: Ace-low Straight" << std::endl;
    std::vector<Card> aceLowStraightCards = {
        Card(Card::ACE, Card::HEARTS),
        Card(Card::TWO, Card::DIAMONDS),
        Card(Card::THREE, Card::CLUBS),
        Card(Card::FOUR, Card::SPADES),
        Card(Card::FIVE, Card::HEARTS)
    };
    std::cout << "Cards: ";
    for (const auto& card : aceLowStraightCards) {
        std::cout << card.toString() << " ";
    }
    std::cout << "\nResult: " << royalFlushChecker.checkHand(aceLowStraightCards) << std::endl << std::endl;

    // Test: Flush House
    std::cout << "Test: Flush House" << std::endl;
    std::vector<Card> flushHouseCards = {
        Card(Card::KING, Card::HEARTS),
        Card(Card::KING, Card::HEARTS),
        Card(Card::KING, Card::HEARTS),
        Card(Card::QUEEN, Card::HEARTS),
        Card(Card::QUEEN, Card::HEARTS)
    };
    std::cout << "Cards: ";
    for (const auto& card : flushHouseCards) {
        std::cout << card.toString() << " ";
    }
    std::cout << "\nResult: " << royalFlushChecker.checkHand(flushHouseCards) << std::endl << std::endl;

    // Test 1: Royal Flush
    std::cout << "Test 1: Royal Flush" << std::endl;
    std::vector<Card> royalFlushCards = {
        Card(Card::ACE, Card::HEARTS),
        Card(Card::KING, Card::HEARTS),
        Card(Card::QUEEN, Card::HEARTS),
        Card(Card::JACK, Card::HEARTS),
        Card(Card::TEN, Card::HEARTS)
    };
    std::cout << "Cards: ";
    for (const auto& card : royalFlushCards) {
        std::cout << card.toString() << " ";
    }
    std::cout << "\nResult: " << royalFlushChecker.checkHand(royalFlushCards) << std::endl << std::endl;

    // Test 2: Straight Flush
    std::cout << "Test 2: Straight Flush" << std::endl;
    std::vector<Card> straightFlushCards = {
        Card(Card::NINE, Card::SPADES),
        Card(Card::EIGHT, Card::SPADES),
        Card(Card::SEVEN, Card::SPADES),
        Card(Card::SIX, Card::SPADES),
        Card(Card::FIVE, Card::SPADES)
    };
    std::cout << "Cards: ";
    for (const auto& card : straightFlushCards) {
        std::cout << card.toString() << " ";
    }
    std::cout << "\nResult: " << royalFlushChecker.checkHand(straightFlushCards) << std::endl << std::endl;

    return 0;
}
