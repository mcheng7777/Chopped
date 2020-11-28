#include "playgame.h"

PlayGame::PlayGame(QWidget *parent) :
    QWidget(parent)

{
    // Initiate all widgets of the stacked widget
    game = new QStackedWidget;
    main_page = new MainWindow;
    options_page = new Options;
    ingredientsInstructions_page = new Instructions;
    riceInstructions_page = new Instructions;
    choppingInstructions_page = new Instructions;
    sushiInstructions_page = new Instructions;
    rice_page = new CookRice;
    sushi_page = new RollSushi;
    chopping_page = new ChoppingGame;
    ingredients_page = new Ingredients;
    congrats_page = new Congrats;

    // all all widgets to the stacked widget
    game->addWidget(main_page);
    game->addWidget(options_page);
    game->addWidget(ingredientsInstructions_page);
    game->addWidget(ingredients_page);
    game->addWidget(riceInstructions_page);
    game->addWidget(rice_page);
    game->addWidget(choppingInstructions_page);
    game->addWidget(chopping_page);
    game->addWidget(sushiInstructions_page);
    game->addWidget(sushi_page);
    game->addWidget(congrats_page);

    // create a central layout on the stacked widget and set the layout
    QVBoxLayout *centrallayout = new QVBoxLayout;
    centrallayout->addWidget(game);
    setLayout(centrallayout);

    // connect all the windows together

    // connect the opening page to the options page
    QObject::connect(main_page->start, &QPushButton::clicked, this, &PlayGame::go_to_options_win);

    //connect the options page to the instructions page of the ingredients game
    QObject::connect(options_page->item, &QPushButton::clicked, this, &PlayGame::go_to_ingredientsInstructions_win);

    // connect the instructions page of the ingredients game to the ingredients game
    QObject::connect(ingredientsInstructions_page->next, &QPushButton::clicked, this, &PlayGame::go_to_ingredients_win);


    // connect the ingredients page to the instructions page of the cooking rice game
    QObject::connect(ingredients_page->next, &QPushButton::clicked, this, &PlayGame::go_to_riceInstructions_win);

    // connect the instructions page of the cooking rice game to the cooking rice gmae
    QObject::connect(riceInstructions_page->next, &QPushButton::clicked, this, &PlayGame::go_to_rice_win);

    // connect the cooking rice game to the instructions page of the chopping game
    QObject::connect(rice_page->rnextgame, &QPushButton::clicked, this, &PlayGame::go_to_choppingInstructions_win);

    // connect the instructions page of the chopping game to the chopping game
    QObject::connect(choppingInstructions_page->next, &QPushButton::clicked, this, &PlayGame::go_to_chopping_win);

    // connect the chopping game to the instructions page of the rolling sushi game
    QObject::connect(chopping_page->cnextgame, &QPushButton::clicked, this, &PlayGame::go_to_sushiInstructions_win);

    // connect the instructions page of the rolling sushi game to the rolling sushi game
    QObject::connect(sushiInstructions_page->next, &QPushButton::clicked, this, &PlayGame::go_to_sushi_win);

    // connect the sushi game to the congrats window
    QObject::connect(sushi_page->finish, &QPushButton::clicked, this, &PlayGame::go_to_congrats_win);

    // connections to add scores from each game to the total score
    QObject::connect(ingredients_page->next, &QPushButton::clicked, this, &PlayGame::addIngredientsScore);
    QObject::connect(rice_page->rnextgame, &QPushButton::clicked, this, &PlayGame::addRiceScore);
    QObject::connect(chopping_page->cnextgame, &QPushButton::clicked, this, &PlayGame::addChoppingScore);
    QObject::connect(congrats_page->generateScore, &QPushButton::clicked, this, &PlayGame::addSushiScore);
    QObject::connect(congrats_page->generateScore, &QPushButton::clicked, this, &PlayGame::displayTotScore);

    // connect end of one player's game to the music stoping
    QObject::connect(congrats_page->endGame, &QPushButton::clicked, main_page, &MainWindow::stopMusic);



}

void PlayGame::go_to_main_win()
{
    game->setCurrentIndex(0);
}

void PlayGame::go_to_options_win() {

    game->setCurrentIndex(1);
}

void PlayGame::go_to_ingredientsInstructions_win()
{
    ingredientsInstructions_page->instruct->setText("Your first task is to choose the right ingredients \nOnly click on ingredients used in sushi \nYou have 20 seconds");
    game->setCurrentIndex(2);
}

void PlayGame::go_to_ingredients_win()
{
    game->setCurrentIndex(3);
}

void PlayGame::go_to_riceInstructions_win()
{
    riceInstructions_page->instruct->setText("Your next task is to cook the rice without undercooking or burning it \nUse the spacebar to stop the bar as close to the center as possible \nYou have 10 seconds");
    game->setCurrentIndex(4);
}
void PlayGame::go_to_rice_win()
{
    game->setCurrentIndex(5);
}

void PlayGame::go_to_choppingInstructions_win()
{
    choppingInstructions_page->instruct->setText("Your next task is to chop sashimi \nUse the arrow keys to move the knife over the fish and the spacebar to cut the fish \nYou have 10 seconds");
    game->setCurrentIndex(6);
}
void PlayGame::go_to_chopping_win()
{
    game->setCurrentIndex(7);
}

void PlayGame::go_to_sushiInstructions_win()
{
    sushiInstructions_page->instruct->setText("Your final task is to roll the sushi. \nYou will have 30 seconds to enter as many 'words' as possible. \nThe more words you get correct, the more progress you will make on rolling the sushi.");
    game->setCurrentIndex(8);
}
void PlayGame::go_to_sushi_win()
{
    game->setCurrentIndex(9);
}

void PlayGame::go_to_congrats_win()
{
    game->setCurrentIndex(10);
}

void PlayGame::addSushiScore()
{
    total_score += sushi_page->get_score();
}

void PlayGame::addRiceScore()
{
    total_score += rice_page->movingbar->get_score();
}

void PlayGame::addChoppingScore() {
    total_score += chopping_page->get_score();
}

void PlayGame::addIngredientsScore()
{
    total_score += ingredients_page->get_score();
}

int PlayGame::getTotScore() const { return total_score;}

void PlayGame::displayTotScore()
{
    congrats_page->generateScore->setEnabled(false);
    QString score = QString::number(total_score);
    congrats_page->generateScore->setText("Your Score is: " + score);
}
