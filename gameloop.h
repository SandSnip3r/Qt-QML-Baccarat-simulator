#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <QThread>
#include "shoe.h"

class GameLoop : public QThread
{
    Q_OBJECT
    void run() Q_DECL_OVERRIDE;
private:
    bool running{false};
    Shoe shoe;
public:
    explicit GameLoop(QThread *parent = 0);
    void stop();
signals:
    void gameFinished(const Game &game);
};

#endif // GAMELOOP_H
