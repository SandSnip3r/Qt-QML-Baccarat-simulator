#include "shoe.h"
#include <vector>
#include <QDebug>
#include <chrono>

Shoe::Shoe() {
    initializeRandomEngine();
    cards.reserve(52*DECK_COUNT);
}

void Shoe::initializeRandomEngine() {
    std::vector<int> seeds;
    seeds.reserve(std::mt19937::state_size);
    for (uint i=0; i<std::mt19937::state_size; ++i) {
        auto now = std::chrono::high_resolution_clock::now();
        seeds.emplace_back(std::chrono::duration_cast<std::chrono::nanoseconds>(now.time_since_epoch()).count());
    }
    std::seed_seq ss(seeds.begin(), seeds.end());
    eng = std::mt19937(ss);
}

void Shoe::newShoe() {
    std::vector<Card> stdCards;
    stdCards.reserve(52*DECK_COUNT);
    for (Card::Suit s=Card::Suit::Hearts; s<Card::Suit::SuitEnd; ++s) {
        for (Card::Value v=Card::Value::Ace; v<Card::Value::ValueEnd; ++v) {
            for (int i=0; i<DECK_COUNT; ++i) {
                stdCards.emplace_back(v,s);
            }
        }
    }
    std::shuffle(stdCards.begin(), stdCards.end(), eng);

    cards = QVector<Card>::fromStdVector(stdCards);
}

Card Shoe::dealCard() {
    Card c = cards.front();
    cards.pop_front();
    return c;
}

Game Shoe::getNextGame() {
    static const bool BANKER_DRAWS[8][10] = {{ 1,1,1,1,1,1,1,1,1,1 },
                                             { 1,1,1,1,1,1,1,1,1,1 },
                                             { 1,1,1,1,1,1,1,1,1,1 },
                                             { 1,1,1,1,1,1,1,1,0,1 },
                                             { 0,0,1,1,1,1,1,1,0,0 },
                                             { 0,0,0,0,1,1,1,1,0,0 },
                                             { 0,0,0,0,0,0,1,1,0,0 },
                                             { 0,0,0,0,0,0,0,0,0,0 }};
    if (cards.size() < CUT_CARD_POS) {
        newShoe();
    }
    Card p1 = dealCard();
    Card b1 = dealCard();
    Card p2 = dealCard();
    Card b2 = dealCard();
    quint8 playerScore = (p1.getScore() + p2.getScore()) % 10;
    quint8 bankerScore = (b1.getScore() + b2.getScore()) % 10;

    Game game;
    game.cards["p1"] = p1;
    game.cards["b1"] = b1;
    game.cards["p2"] = p2;
    game.cards["b2"] = b2;

    if (playerScore < 8 && bankerScore < 8) {
        //Not a natural
        if (playerScore <= 5) {
            //Player draws
            Card p3 = dealCard();
            game.cards["p3"] = p3;
            playerScore += p3.getScore();
            playerScore %= 10;
            if (BANKER_DRAWS[bankerScore][p3.getScore()]) {
                //Banker draws third
                Card b3 = dealCard();
                game.cards["b3"] = b3;
                bankerScore += b3.getScore();
                bankerScore %= 10;
            }
        } else {
            //Player doesnt draw
            if (bankerScore <= 5) {
                //Banker draws
                Card b3 = dealCard();
                game.cards["b3"] = b3;
                bankerScore += b3.getScore();
                bankerScore %= 10;
            }
        }
    } else {
        //Natural
    }

    game.playerScore = playerScore;
    game.bankerScore = bankerScore;

    return game;
}
