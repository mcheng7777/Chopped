#include "cookrice.h"
#include "movingitem.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>


CookRice::CookRice(QWidget *parent) :
    QMainWindow(parent)
{
    riceWindow = new QWidget;
    setFixedSize(900, 700);

    QLabel* riceTitle = new QLabel("Cook the Rice");

    // change the font of the title of this game
    QFontDatabase::addApplicationFont(":/fonts/gooddog.otf");
    QFont titlefont("GoodDog", 80, 1);
    riceTitle->setFont(titlefont);
    riceTitle->setAttribute(Qt::WA_TranslucentBackground);
    riceTitle->setAlignment(Qt::AlignCenter);

    // create a layout for the window
    riceLayout = new QVBoxLayout(riceWindow);
    riceLayout->addWidget(riceTitle);

    // create a push button to start the moving widget
    start = new QPushButton("start");
    start->setFocusPolicy(Qt::ClickFocus);
    riceLayout->addWidget(start);


    // create a push button for the dish that will start the game
    rnextgame = new QPushButton("Next");
    riceLayout->setAlignment(Qt::AlignCenter);

    // create labels of fixed size and color that will correspond to locations where the user can stop the moving widget
    QLabel* label1 = new QLabel;
    QLabel* label2 = new QLabel;
    QLabel* label3 = new QLabel;
    QLabel* label4 = new QLabel;
    QLabel* label5 = new QLabel;

    label1->setFixedSize(250,50);
    label2->setFixedSize(190,50);
    label3->setFixedSize(20,50);
    label4->setFixedSize(190,50);
    label5->setFixedSize(250,50);

    label1->setStyleSheet("QLabel { background-color : red; }");
    label2->setStyleSheet("QLabel { background-color : yellow; }");
    label3->setStyleSheet("QLabel { background-color : green; }");
    label4->setStyleSheet("QLabel { background-color : yellow; }");
    label5->setStyleSheet("QLabel { background-color : red; }");

    //add these widgets to a new grid layout
    QGridLayout* layout = new QGridLayout;
    layout->setSpacing(0);
    layout->addWidget(label1,0,0);
    layout->addWidget(label2,0,1);
    layout->addWidget(label3,0,2);
    layout->addWidget(label4,0,3);
    layout->addWidget(label5,0,4);


    // create a MovingItem object that will be the black bar that moves across the screen and add this object to its own layout
    movingbar = new MovingItem;
    movingbar->setFocusPolicy(Qt::StrongFocus);
    movingLayout = new QHBoxLayout;
    movingLayout->addWidget(movingbar);

    // hide this bar until the user indicates that they want to start
    movingbar->setVisible(false);

    // add the moving item layout to the grid layout with the colored labels - overlap these layouts so that the bar will be on top of the colored labels
    layout->addLayout(movingLayout,0,0,7,7);
    QWidget* bar = new QWidget;
    bar->setLayout(layout);
    riceLayout->addWidget(bar);


    // create a central widget and set the layout on this widget
    QWidget* center = new QWidget;
    center->setLayout(riceLayout);
    center->setObjectName("center");
    setCentralWidget(center);

    // set the background image
    // picture obtained from https://www.istockphoto.com/dk/photos/kitchen-background?mediatype=photography&phrase=kitchen%20background&sort=mostpopular
    center->setStyleSheet("QWidget#center {background-image: url(:/pictures/kitchen_background.jpg);}");

    // connect the start button to the start of the moving item moving back and forth
    QObject::connect(start, &QPushButton::clicked, this, &CookRice::moveItem);

    // connect clicking the space bar to ending the game
    QObject::connect(movingbar, &MovingItem::keyIsPressed, this, &CookRice::makeButtonAppear);

}

void CookRice::makeButtonAppear()
{
    movingbar->setEnabled(false);  // disable the moving item object
    start->hide();

    QString num = QString::number(movingbar->get_score());  // get the score

    QLabel* points = new QLabel("Score: " + num + "/25 points ");
    points->setAlignment(Qt::AlignCenter);

    QLabel* message = new QLabel("testteext");
    message->setAlignment(Qt::AlignCenter);
    QLabel* label_pic = new QLabel;
    label_pic->setAlignment(Qt::AlignCenter);

    if (num == "25") {
        message->setText("Your rice is perfectly cooked!");

        //picture obtained from: http://www.clipartpanda.com/categories/rice-clip-art-free
        QPixmap chef(":/pictures/rice.png");
        label_pic->setPixmap(chef);
    }
    if (num == "15") {
        message->setText("Your rice is slightly undercooked");

        //picture obtained from: http://pngimg.com/imgs/food/rice/
        QPixmap chef(":/pictures/undercooked_rice.png");
        label_pic->setPixmap(chef);
    }
    if (num == "5") {
        message->setText("Yikes! You burned the rice");

        //picture obtained from: https://www.collaboratemarketing.com/modernmarketing/2012/03/digital-strategy-sessions-and-why-im-wrong.html
        QPixmap chef(":/pictures/burnt_rice.png");
        label_pic->setPixmap(chef);
    }
    riceLayout->addWidget(message);
    riceLayout->addWidget(points);
    riceLayout->addWidget(label_pic);
    riceLayout->addWidget(rnextgame);
    rnextgame->setFocusPolicy(Qt::ClickFocus);

}


void CookRice::moveItem()
{
    movingbar->setVisible(true);   // make the moving item (black bar) visible
    focusNextPrevChild(true);   // bring the moving item into focus
    movingbar->startMovement();  // start movement
}

