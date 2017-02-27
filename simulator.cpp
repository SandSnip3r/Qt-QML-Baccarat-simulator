#include <QThread>
#include <QDebug>
#include "simulator.h"

Simulator::Simulator(QObject *parent) : QObject(parent) {
    //Initialize dummy game
    mostRecentGame.cards["p1"] = Card(Card::Value::Four, Card::Suit::Hearts);
    mostRecentGame.cards["b1"] = Card(Card::Value::Four, Card::Suit::Spades);
    mostRecentGame.cards["p2"] = Card(Card::Value::Four, Card::Suit::Diamonds);
    mostRecentGame.cards["b2"] = Card(Card::Value::Four, Card::Suit::Clubs);
    mostRecentGame.bankerScore = 8;
    mostRecentGame.playerScore = 8;
}

bool Simulator::isRunning() const {
    return (gameLoop != nullptr);
}

void Simulator::play() {
    if (gameLoop == nullptr) {
        qDebug() << "Start";
        gameLoop = new GameLoop;
        connect(gameLoop, &GameLoop::gameFinished, this, &Simulator::gameFinished);
        connect(gameLoop, &GameLoop::finished, gameLoop, &QObject::deleteLater);
        gameLoop->start();
    } else {
        qDebug() << "Stop";
        gameLoop->stop();
        gameLoop = nullptr;
    }
    emit runningChanged();
}

void Simulator::gameFinished(const Game &game) {
    mostRecentGame = game;
    ++gamePlayedCount;
    emit gameCountUpdated();
    if (gamePlayedCount%1000 == 0) {
        emit mostRecentGameUpdated();
    }
}

int Simulator::getGamePlayedCount() const {
    return gamePlayedCount;
}

int Simulator::getPlayerScore() const {
    return mostRecentGame.playerScore;
}

int Simulator::getBankerScore() const {
    return mostRecentGame.bankerScore;
}

QString Simulator::getP1CardString() const {
    return mostRecentGame.cards["p1"].getString();
}

QString Simulator::getB1CardString() const {
    return mostRecentGame.cards["b1"].getString();
}

QString Simulator::getP2CardString() const {
    return mostRecentGame.cards["p2"].getString();
}

QString Simulator::getB2CardString() const {
    return mostRecentGame.cards["b2"].getString();
}

QString Simulator::getP3CardString() const {
    if (mostRecentGame.cards.find("p3") != mostRecentGame.cards.end()) {
        return mostRecentGame.cards["p3"].getString();
    } else {
        return "";
    }
}

QString Simulator::getB3CardString() const {
    if (mostRecentGame.cards.find("b3") != mostRecentGame.cards.end()) {
        return mostRecentGame.cards["b3"].getString();
    } else {
        return "";
    }
}
