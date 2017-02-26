#ifndef GAME_H
#define GAME_H

#include <QHash>
#include <QMetaType>
#include "card.h"

class Game {
private:
public:
    QHash<QString, Card> cards;
    quint8 bankerScore, playerScore;
};

Q_DECLARE_METATYPE(Game);

#endif // GAME_H
