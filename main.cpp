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
    RoyalFlushChecker royalFlushChecker;
    StraightFlushChecker straightFlushChecker;
    FiveOfAKindChecker fiveOfAKindChecker;
    FlushFiveChecker flushFiveChecker;
    FlushHouseChecker flushHouseChecker;
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
    straightFlushChecker.setNextChecker(&fiveOfAKindChecker);
    fiveOfAKindChecker.setNextChecker(&flushFiveChecker);
    flushFiveChecker.setNextChecker(&flushHouseChecker);
    flushHouseChecker.setNextChecker(&fourOfAKindChecker);
    fourOfAKindChecker.setNextChecker(&fullHouseChecker);
    fullHouseChecker.setNextChecker(&flushChecker);
    flushChecker.setNextChecker(&straightChecker);
    straightChecker.setNextChecker(&threeOfAKindChecker);
    threeOfAKindChecker.setNextChecker(&twoPairChecker);
    twoPairChecker.setNextChecker(&pairChecker);
    pairChecker.setNextChecker(&highCardChecker);

    // Test cases
    std::cout << "=== Balatro Hand Checker - Chain of Responsibility Pattern ===" << std::endl;
    std::cout << std::endl;

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

    // Test 3: Four of a Kind
    std::cout << "Test 3: Four of a Kind" << std::endl;
    std::vector<Card> fourOfAKindCards = {
        Card(Card::KING, Card::HEARTS),
        Card(Card::KING, Card::DIAMONDS),
        Card(Card::KING, Card::CLUBS),
        Card(Card::KING, Card::SPADES),
        Card(Card::FIVE, Card::HEARTS)
    };
    std::cout << "Cards: ";
    for (const auto& card : fourOfAKindCards) {
        std::cout << card.toString() << " ";
    }
    std::cout << "\nResult: " << royalFlushChecker.checkHand(fourOfAKindCards) << std::endl << std::endl;

    // Test 4: Full House
    std::cout << "Test 4: Full House" << std::endl;
    std::vector<Card> fullHouseCards = {
        Card(Card::QUEEN, Card::HEARTS),
        Card(Card::QUEEN, Card::DIAMONDS),
        Card(Card::QUEEN, Card::CLUBS),
        Card(Card::FIVE, Card::SPADES),
        Card(Card::FIVE, Card::HEARTS)
    };
    std::cout << "Cards: ";
    for (const auto& card : fullHouseCards) {
        std::cout << card.toString() << " ";
    }
    std::cout << "\nResult: " << royalFlushChecker.checkHand(fullHouseCards) << std::endl << std::endl;

    // Test 5: Flush
    std::cout << "Test 5: Flush" << std::endl;
    std::vector<Card> flushCards = {
        Card(Card::TWO, Card::CLUBS),
        Card(Card::FIVE, Card::CLUBS),
        Card(Card::SEVEN, Card::CLUBS),
        Card(Card::JACK, Card::CLUBS),
        Card(Card::KING, Card::CLUBS)
    };
    std::cout << "Cards: ";
    for (const auto& card : flushCards) {
        std::cout << card.toString() << " ";
    }
    std::cout << "\nResult: " << royalFlushChecker.checkHand(flushCards) << std::endl << std::endl;

    // Test 6: Straight
    std::cout << "Test 6: Straight" << std::endl;
    std::vector<Card> straightCards = {
        Card(Card::NINE, Card::HEARTS),
        Card(Card::EIGHT, Card::DIAMONDS),
        Card(Card::SEVEN, Card::CLUBS),
        Card(Card::SIX, Card::SPADES),
        Card(Card::FIVE, Card::HEARTS)
    };
    std::cout << "Cards: ";
    for (const auto& card : straightCards) {
        std::cout << card.toString() << " ";
    }
    std::cout << "\nResult: " << royalFlushChecker.checkHand(straightCards) << std::endl << std::endl;

    // Test 7: Three of a Kind
    std::cout << "Test 7: Three of a Kind" << std::endl;
    std::vector<Card> threeOfAKindCards = {
        Card(Card::JACK, Card::HEARTS),
        Card(Card::JACK, Card::DIAMONDS),
        Card(Card::JACK, Card::CLUBS),
        Card(Card::KING, Card::SPADES),
        Card(Card::FIVE, Card::HEARTS)
    };
    std::cout << "Cards: ";
    for (const auto& card : threeOfAKindCards) {
        std::cout << card.toString() << " ";
    }
    std::cout << "\nResult: " << royalFlushChecker.checkHand(threeOfAKindCards) << std::endl << std::endl;

    // Test 8: Two Pair
    std::cout << "Test 8: Two Pair" << std::endl;
    std::vector<Card> twoPairCards = {
        Card(Card::TEN, Card::HEARTS),
        Card(Card::TEN, Card::DIAMONDS),
        Card(Card::FOUR, Card::CLUBS),
        Card(Card::FOUR, Card::SPADES),
        Card(Card::KING, Card::HEARTS)
    };
    std::cout << "Cards: ";
    for (const auto& card : twoPairCards) {
        std::cout << card.toString() << " ";
    }
    std::cout << "\nResult: " << royalFlushChecker.checkHand(twoPairCards) << std::endl << std::endl;

    // Test 9: Pair
    std::cout << "Test 9: Pair" << std::endl;
    std::vector<Card> pairCards = {
        Card(Card::SEVEN, Card::HEARTS),
        Card(Card::SEVEN, Card::DIAMONDS),
        Card(Card::KING, Card::CLUBS),
        Card(Card::QUEEN, Card::SPADES),
        Card(Card::JACK, Card::HEARTS)
    };
    std::cout << "Cards: ";
    for (const auto& card : pairCards) {
        std::cout << card.toString() << " ";
    }
    std::cout << "\nResult: " << royalFlushChecker.checkHand(pairCards) << std::endl << std::endl;

    // Test 10: High Card
    std::cout << "Test 10: High Card" << std::endl;
    std::vector<Card> highCardCards = {
        Card(Card::TWO, Card::HEARTS),
        Card(Card::FIVE, Card::DIAMONDS),
        Card(Card::EIGHT, Card::CLUBS),
        Card(Card::JACK, Card::SPADES),
        Card(Card::ACE, Card::HEARTS)
    };
    std::cout << "Cards: ";
    for (const auto& card : highCardCards) {
        std::cout << card.toString() << " ";
    }
    std::cout << "\nResult: " << royalFlushChecker.checkHand(highCardCards) << std::endl << std::endl;

    return 0;
}
