#ifndef SHOE_H
#define SHOE_H

#include <QVector>
#include <random>
#include "card.h"
#include "game.h"

class Shoe {
private:
    const int DECK_COUNT{8};
    const int CUT_CARD_POS{24};
    std::mt19937 eng;
    QVector<Card> cards;
    void initializeRandomEngine();
    void newShoe();
    Card dealCard();
public:
    Shoe();
    Game getNextGame();
};

#endif // SHOE_H
