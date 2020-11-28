#include "options.h"
#include "instructions.h"
Options::Options(QWidget *parent) :
    QMainWindow(parent)
{
    // create an options window of fixed size
    optionsWindow = new QWidget;
    setFixedSize(900, 700);

    // create two labels
    QLabel* optionsTitle = new QLabel("Options Menu");
    QLabel* select = new QLabel("Select dish: ");
    select->setAlignment(Qt::AlignCenter);

    // set the font for the "options menu" label
    QFontDatabase::addApplicationFont(":/fonts/gooddog.otf");
    QFont titlefont("GoodDog", 80, 1);
    optionsTitle->setFont(titlefont);

    // set the font for the "select dish" label
    QFont sfont;
    sfont.setPointSize(20);
    select->setFont(sfont);

    // create a layout for the window
    QVBoxLayout* optionsLayout = new QVBoxLayout(optionsWindow);
    //optionsLayout->setAlignment(Qt::AlignHCenter);
    optionsLayout->addWidget(optionsTitle);
    optionsLayout->addWidget(select);

    // create a push button for the dish that will start the game
    item = new QPushButton("Sushi");
    item->setFocusPolicy(Qt::ClickFocus);
    optionsLayout->addWidget(item);
    optionsLayout->setAlignment(Qt::AlignCenter);

    // create a widget with the layout and set this to be the central widget of the window
    QWidget* center = new QWidget;
    center->setLayout(optionsLayout);
    setCentralWidget(center);

    // set the background
    // image obtained from: gttps://pngtree.com/freebackground/japanese-food-poster-background_811373.html
    this->setStyleSheet("QWidget{background-image: url(:/pictures/options_bkgrd.jpg);}");

}
