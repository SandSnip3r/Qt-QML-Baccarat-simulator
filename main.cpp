#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "simulator.h"
#include "game.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qRegisterMetaType<Game>();
    Simulator simulator;
    QQmlContext *ctx = engine.rootContext();
    ctx->setContextProperty("simulator", &simulator);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
