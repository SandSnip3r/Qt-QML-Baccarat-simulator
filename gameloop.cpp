#include "gameloop.h"
#include <random>
#include <QDebug>

GameLoop::GameLoop(QThread *parent) : QThread(parent) {
}

void GameLoop::run() {
    running = true;

    while (true) {
        if (!running) {
            break;
        }
        Game game = shoe.getNextGame();
        emit gameFinished(game);
        QThread::usleep(333333);
    }
}

void GameLoop::stop() {
    running = false;
}
