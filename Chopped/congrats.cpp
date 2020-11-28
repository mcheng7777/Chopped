#include "congrats.h"

Congrats::Congrats(QWidget *parent) :
    QMainWindow(parent)
{

    congratsWindow = new QWidget;
    setFixedSize(900, 700);

    QLabel* congrats = new QLabel("CONGRATS!! \n You made a sushi roll!");
    congrats->setAlignment(Qt::AlignCenter);

    // change the font of the title of this game
    QFontDatabase::addApplicationFont(":/fonts/gooddog.otf");
    QFont titlefont("GoodDog", 50, 1);
    congrats->setFont(titlefont);
    congrats->setAttribute(Qt::WA_TranslucentBackground);

    // create a layout for the window
    congratsLayout = new QVBoxLayout(congratsWindow);
    congratsLayout->addWidget(congrats);

    // add image of a bento box
    // image obtained from: https://pngtree.com/free-png-vectors/sushi-cartoon
    QPixmap bentobox(":/pictures/sushi.png");
    QLabel* bento_pic = new QLabel;
    bento_pic->setPixmap(bentobox);
    bento_pic->setAttribute(Qt::WA_TranslucentBackground);
    congratsLayout->addWidget(bento_pic);

    // create a push button to generate the score for the player
    generateScore = new QPushButton("Generate my score");
    generateScore->setFocusPolicy(Qt::ClickFocus);
    congratsLayout->addWidget(generateScore);
    congratsLayout->setAlignment(Qt::AlignCenter);

    // create a push button for the dish that will start the game
    endGame = new QPushButton("Exit");
    endGame->setFocusPolicy(Qt::ClickFocus);
    congratsLayout->addWidget(endGame);
    congratsLayout->setAlignment(Qt::AlignCenter);

    // create a central widget and set the layout on this widget
    QWidget* center = new QWidget;
    center->setLayout(congratsLayout);
    setCentralWidget(center);

    // set the background image
    // image obtained from: https://www.123rf.com/photo_27490580_stock-vector-vector-template-of-vibrant-colorful-confetti-in-the-colors-of-the-rainbow-on-white-with-copyspace-fo.html
    this->setStyleSheet("QWidget{background-image: url(:/pictures/confetti.jpg);}");



}


