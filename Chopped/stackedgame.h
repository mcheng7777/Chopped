#ifndef STACKEDGAME_H
#define STACKEDGAME_H

#include <QWidget>
#include <QStackedWidget>
#include <QMainWindow>
#include "playgame.h"
#include "final.h"

/**
 * @brief The StackedGame class
 * sets up the game for two players
 * stackedwidget contains two PlayGames (one for each player)
 * finds the winner by comparing scores of each player
 */
class StackedGame : public QWidget {
    Q_OBJECT

public:

    /**
     * @brief constructor the stacked game
     * @param parent - nullptr
     */
    explicit StackedGame(QWidget* parent = nullptr);

    /**
     * @brief destructor for the stacked game
     */
    ~StackedGame() {}

public slots:
    /**
     * @brief switch to player two
     */
    void nextPlayer();

    /**
     * @brief display the final page that shows the winner
     */
    void displayFinalPage();

    /**
     * @brief find the winner by comparing scores
     */
    void get_the_winner();

private:
    QStackedWidget* stackedGame;
    Final* final_page;
    PlayGame* one;
    PlayGame* two;

};

#endif // STACKEDGAME_H
