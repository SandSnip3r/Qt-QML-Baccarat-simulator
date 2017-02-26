#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <QObject>
#include "gameloop.h"

class Simulator : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool running READ isRunning NOTIFY runningChanged)
    Q_PROPERTY(int gamePlayedCount READ getGamePlayedCount NOTIFY mostRecentGameUpdated)
    Q_PROPERTY(int playerScore READ getPlayerScore NOTIFY mostRecentGameUpdated)
    Q_PROPERTY(int bankerScore READ getBankerScore NOTIFY mostRecentGameUpdated)
    Q_PROPERTY(QString p1CardString READ getP1CardString NOTIFY mostRecentGameUpdated)
    Q_PROPERTY(QString b1CardString READ getB1CardString NOTIFY mostRecentGameUpdated)
    Q_PROPERTY(QString p2CardString READ getP2CardString NOTIFY mostRecentGameUpdated)
    Q_PROPERTY(QString b2CardString READ getB2CardString NOTIFY mostRecentGameUpdated)
    Q_PROPERTY(QString p3CardString READ getP3CardString NOTIFY mostRecentGameUpdated)
    Q_PROPERTY(QString b3CardString READ getB3CardString NOTIFY mostRecentGameUpdated)
private:
    GameLoop *gameLoop{nullptr};
    int gamePlayedCount{0};
    Game mostRecentGame;
public:
    explicit Simulator(QObject *parent = 0);
    bool isRunning() const;
    void gameFinished(const Game &game);
    int getGamePlayedCount() const;
    int getPlayerScore() const;
    int getBankerScore() const;
    QString getP1CardString() const;
    QString getB1CardString() const;
    QString getP2CardString() const;
    QString getB2CardString() const;
    QString getP3CardString() const;
    QString getB3CardString() const;
signals:
    void runningChanged();
    void mostRecentGameUpdated();
public slots:
    void play();
};

#endif // SIMULATOR_H
