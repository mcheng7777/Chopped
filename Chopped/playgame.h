// this class will coordinate all of the classes that will be involved in the game

#include "mainwindow.h"
#include "instructions.h"
#include "options.h"
#include "rollsushi.h"
#include "choppinggame.h"
#include "cookrice.h"
#include "ingredients.h"
#include "congrats.h"

#ifndef PLAYGAME_H
#define PLAYGAME_H

#include <QWidget>
#include <QPixmap>
#include <QStackedWidget>

/**
 * @brief The PlayGame class
 * sets up the game for each player on a stacked widget
 * includes all connections within one player's turn
 */
class PlayGame : public QWidget {
    Q_OBJECT
public:
    /**
     * @brief constructor for the PlayGame class
     * @param parent - nullptr
    */
    explicit PlayGame(QWidget* parent = nullptr);

    /**
     * @brief destructor for the PlayGame class
    */
    ~PlayGame() {}

    /**
     * @brief gets the total score of all the mini games
     * @return an int
     */
    int getTotScore() const;

    Congrats* congrats_page;

public slots:
    /**
     * @brief go to the main window
    */
    void go_to_main_win();

    /**
     * @brief go to the instructions for the ingredients game
    */
    void go_to_ingredientsInstructions_win();

    /**
     * @brief go to the instructions for the cooking rice game
    */
    void go_to_riceInstructions_win();

    /**
     * @brief go to the instructions for the choppng game
    */
    void go_to_choppingInstructions_win();

    /**
     * @brief go to the instructions for the rolling sushi game
    */
    void go_to_sushiInstructions_win();

    /**
     * @brief go to the options page
    */
    void go_to_options_win();

    /**
     * @brief go to the rolling sushi game
    */
    void go_to_sushi_win();

    /**
     * @brief go to the chopping game
    */
    void go_to_chopping_win();

    /**
     * @brief go to the cooking rice game
    */
    void go_to_rice_win();

    /**
     * @brief go to the gathering ingredients game
    */
    void go_to_ingredients_win();

    /**
     * @brief go to the final congratulations page
    */
    void go_to_congrats_win();

    /**
     * @brief add the score from the cooking rice game to the total score
    */
    void addRiceScore();

    /**
     * @brief add the score from the rollong sushi game to the total score
     */
    void addSushiScore();

    /**
     * @brief add the score from the chopping game to the total score
     */
    void addChoppingScore();

    /**
     * @brief add the score from the ingredients game to the total score
     */
    void addIngredientsScore();

    /**
     * @brief get the total score from all games
     */
    void displayTotScore();


private:
    QStackedWidget* game;
    MainWindow* main_page;
    Instructions* ingredientsInstructions_page;
    Instructions* riceInstructions_page;
    Instructions* choppingInstructions_page;
    Instructions* sushiInstructions_page;
    Options* options_page;
    RollSushi* sushi_page;
    ChoppingGame* chopping_page;
    CookRice* rice_page;
    Ingredients* ingredients_page;
    int total_score = 0;



};

#endif // PLAYGAME_H
