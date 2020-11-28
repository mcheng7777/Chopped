#include "final.h"

Final::Final(QWidget *parent) :
    QMainWindow(parent)
{
    finalWindow = new QWidget;
    setFixedSize(900, 700);

    congrats = new QLabel("Congrats to Player X! \n You made the best bento box");
    congrats->setAlignment(Qt::AlignCenter);

    // change the font of the title of this game
    QFontDatabase::addApplicationFont(":/fonts/gooddog.otf");
    QFont titlefont("GoodDog", 50, 1);
    congrats->setFont(titlefont);
    congrats->setAttribute(Qt::WA_TranslucentBackground);

    // create a layout for the window
    QVBoxLayout* finalLayout = new QVBoxLayout(finalWindow);
    finalLayout->addWidget(congrats);

    // add image of a bento box
    // image obtained from: https://www.clipartmax.com/middle/m2i8N4K9i8d3i8K9_ramen-japanese-cuisine-fast-food-japanese-noodles-cartoon-japanese-foods/
    QPixmap bentobox(":/pictures/final_sushi.png");
    QLabel* bento_pic = new QLabel;
    bento_pic->setPixmap(bentobox);
    bento_pic->setAttribute(Qt::WA_TranslucentBackground);
    finalLayout->addWidget(bento_pic);

    // create a push button for the dish that will start the game
    quit = new QPushButton("Exit game");
    finalLayout->addWidget(quit);
    finalLayout->setAlignment(Qt::AlignCenter);

    // create a central widget and set the layout on this widget
    QWidget* center = new QWidget;
    center->setLayout(finalLayout);
    setCentralWidget(center);

    // set the background image
    // image obtained from: https://www.123rf.com/photo_27490580_stock-vector-vector-template-of-vibrant-colorful-confetti-in-the-colors-of-the-rainbow-on-white-with-copyspace-fo.html
    this->setStyleSheet("QWidget{background-image: url(:/pictures/confetti.jpg);}");

   }
