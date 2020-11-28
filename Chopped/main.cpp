#include "mainwindow.h"
#include "cookrice.h"
#include "rollsushi.h"
#include "playgame.h"
#include "stackedgame.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    StackedGame game;
    game.show();

    return a.exec();
}
