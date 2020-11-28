#include "stackedgame.h"

StackedGame::StackedGame(QWidget* parent) : QWidget(parent) {

    stackedGame = new QStackedWidget;

    final_page = new Final();

    // two players
    one = new PlayGame();
    two = new PlayGame();

    stackedGame->addWidget(one);
    stackedGame->addWidget(two);
    stackedGame->addWidget(final_page);

    QVBoxLayout* centrallayout = new QVBoxLayout;
    centrallayout->addWidget(stackedGame);
    setLayout(centrallayout);

    // quit button for first player takes you to the second player's start
    QObject::connect(one->congrats_page->endGame, &QPushButton::clicked, this, &StackedGame::nextPlayer);

    // end of the second player's game takes you to the final winner page
    QObject::connect(two->congrats_page->endGame, &QPushButton::clicked, this, &StackedGame::displayFinalPage);

    // end of second player's game signals for the program to find the winner
    QObject::connect(two->congrats_page->endGame, &QPushButton::clicked, this, &StackedGame::get_the_winner);

    // quit button for the second player exits the game
    QObject::connect(final_page->quit, &QPushButton::clicked, this, &QApplication::quit);



}

void StackedGame::nextPlayer()
{
    stackedGame->setCurrentIndex(1);
}

void StackedGame::displayFinalPage()
{
    stackedGame->setCurrentIndex(2);
}

void StackedGame::get_the_winner() {
    // if player one wins
    if (one->getTotScore() > two->getTotScore()) final_page->congrats->setText("Congratulations to Player 1!\n You made the better sushi roll!");

    // if player 2 wins
    if (one->getTotScore() < two-> getTotScore()) final_page->congrats->setText("Congraulations to Player 2!\n You made the better sushi roll!");

    // if they tied
    if (one->getTotScore() == two->getTotScore()) final_page->congrats->setText("You tied!\n Your sushi rolls were on par with each other!");
}
