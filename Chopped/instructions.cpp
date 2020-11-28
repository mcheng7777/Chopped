#include "instructions.h"

Instructions::Instructions(QWidget *parent) :
    QMainWindow(parent)
{

    instructionsWindow = new QWidget;
    setFixedSize(900,700);

    // create a title label, set the font and background
    QLabel* instructionsTitle = new QLabel("Instructions:");
    QFontDatabase::addApplicationFont(":/fonts/gooddog.otf");
    QFont titlefont("GoodDog", 80, 1);
    instructionsTitle->setFont(titlefont);
    instructionsTitle->setAlignment(Qt::AlignCenter);

    // label with the instructions text
    instruct = new QLabel();

    // set font size and alignment
    QFont instruct_font("", 15, 1);
    instruct->setFont(instruct_font);
    instruct->setParent(instructionsWindow);
    instruct->setAlignment(Qt::AlignHCenter);

    // create a push button that will start the game
    next = new QPushButton("Start game");
    next->setFocusPolicy(Qt::ClickFocus);

    // create a layout
    QVBoxLayout* instructionsLayout = new QVBoxLayout(instructionsWindow);
    instructionsLayout->addWidget(instructionsTitle);
    instructionsLayout->addWidget(instruct);
    instructionsLayout->addWidget(next);
    instructionsLayout->setAlignment(Qt::AlignCenter);

    // create a widget with the layout and set this to be the central widget of the window
    QWidget* center = new QWidget;
    center->setLayout(instructionsLayout);
    setCentralWidget(center);

    // set the background
    // image obtained from: gttps://pngtree.com/freebackground/japanese-food-poster-background_811373.html
    this->setStyleSheet("QWidget{background-image: url(:/pictures/options_bkgrd.jpg);}");

}
