#include "choppinggame.h"

#include <QDebug>
#include <QCoreApplication>
ChoppingGame::ChoppingGame(QWidget *parent) :
   QMainWindow(parent), cnextgame(new QPushButton("next")), score(0)
{

   setFixedSize(900, 700);

   //create the title
   QLabel* choppingTitle = new QLabel("Slice the Sashimi");

   // set the font of the choppingTitle
   QFontDatabase::addApplicationFont(":/fonts/gooddog.otf");
   QFont titlefont("GoodDog", 80, 1);
   choppingTitle->setFont(titlefont);
   choppingTitle->setAttribute(Qt::WA_TranslucentBackground);
   choppingTitle->setAlignment(Qt::AlignCenter);

   // create a grid layout for the window and horizontal box layout
   // set the mainlayout to the grid layout, which contains choppingLayout

   mainLayout = new QVBoxLayout;
   mainLayout->addWidget(choppingTitle);
   instruction = new QLabel("Press 0 to begin");
   instruction->setAlignment(Qt::AlignCenter);
   instruction->setAttribute(Qt::WA_TranslucentBackground);
   mainLayout->addWidget(instruction);

   test = new QWidget;
   grid = new QGridLayout();
   test->setLayout(grid);
   test->setFixedSize(1000,800);
   test->setAttribute(Qt::WA_TranslucentBackground);
   mainLayout->setAlignment(Qt::AlignCenter);
   mainLayout->addWidget(test);

   choppingLayout = new QHBoxLayout();
   choppingLayout->setAlignment(Qt::AlignCenter);
   grid->addLayout(choppingLayout,1,1,7,7);

   // background picture
   // picture obtained from https://www.istockphoto.com/dk/photos/kitchen-background?mediatype=photography&phrase=kitchen%20background&sort=mostpopular
   this->setStyleSheet("QWidget{background-image: url(:/pictures/kitchen_background.jpg);}");


   // create the widget for central widget and set the layout to it
   QWidget* center = new QWidget;
   center->setLayout(mainLayout);
   setCentralWidget(center);

   // create knife and add it to the gridlayout
   k = new knife;

   final = new QLabel();
   final_score = "";

   timer = new QTimer;

   // connect the finished game signal to the next push button appearing
   QObject::connect(k,&knife::finish_chopping,this,&ChoppingGame::make_button_appear);

   // connect the cut sushi signal to adding one to the score
   QObject::connect(k, &knife::CutSushi, this, &ChoppingGame::add_to_score);

   // connect the miss sushi signal to subtracting one from the score
   QObject::connect(k, &knife::MissedSushi, this, &ChoppingGame::minus_score);

   cnextgame->setFocusPolicy(Qt::ClickFocus);
}


int ChoppingGame::get_score() const{
    return score;
}

void ChoppingGame::make_button_appear(){

    final_score = QString::number(get_score());
    final->setText("Your score is "+ final_score + "/10");
    final->setAlignment(Qt::AlignCenter);
    final->setFixedSize(700, 40);
    final->setAttribute(Qt::WA_TranslucentBackground);
    mainLayout->removeWidget(test);
    mainLayout->addWidget(final);
    cnextgame->setFixedSize(700, 20);
    k->clearFocus();
    mainLayout->addWidget(cnextgame);

}

void ChoppingGame::TimerStart() {
    timer->setInterval(10000);   // set the timer for 20 seconds

    // at the end of the interval, stop the timer and end the game
    QObject::connect(timer, &QTimer::timeout, this, &ChoppingGame::TimerStop);
    timer->start();

}

void ChoppingGame::TimerStop () {
    timer->stop();
    k->hidesushi();
    final_score = QString::number(get_score());
    final->setText("Your score is "+ final_score + "/10");
    final->setAlignment(Qt::AlignCenter);
    final->setFixedSize(700, 40);
    final->setAttribute(Qt::WA_TranslucentBackground);
    mainLayout->removeWidget(test);
    mainLayout->addWidget(final);
    cnextgame->setFixedSize(700, 20);
    k->clearFocus();
    mainLayout->addWidget(cnextgame);

}

void ChoppingGame::add_to_score() {
    ++score;
}

void ChoppingGame::minus_score() {
    if (get_score() == 0) score = 0;
    else --score;
}

void ChoppingGame::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()) {

    case Qt::Key_0: {   // when the user presses the '0' key start the timer and begin typing in the line edit
        instruction->hide();
        grid->addWidget(k);
        k->setFocus();
        TimerStart();
    }
    }
    return QWidget::keyPressEvent(event);
}

void knife::showsushi(){
    m_showsushi=true;
    update();
}
void knife::hidesushi(){
    m_showsushi=false;
    error=false;
}


knife::knife(QWidget* parent) : QMainWindow (parent), x(30),y(10), sx(1),sy(300),m_showsushi(true),c(0),error(false){
}
void knife::paintEvent(QPaintEvent* event){

    if(error==true && c!=10){ // if the error bool is true, ouptut that the user did not cut the sushi
        QRect rect(10,10,500,500);
        QPainter painter(this);
        painter.drawText(rect, Qt::AlignCenter, tr("You did not cut the sushi!"));
    }
    if(m_showsushi){ // if the sushi and knife should be shown, keep showing them
        // picture of sashimi
        //https://www.uihere.com/free-cliparts/search?q=sashimi+Salmon&page=29
        QPixmap cutsashimi(":/pictures/sashimi_cut.png");

        QPainter painter(this);
        setStyleSheet("background:transparent;");
        painter.drawPixmap(sx,sy,cutsashimi);

        //image obtained from http://worldartsme.com/knife-clipart.html#gal_post_5330_knife-clipart-1.jpg
        QPixmap knife(":/pictures/knife.png");
        setStyleSheet("background:transparent;");
        painter.drawPixmap(x,y,knife);
        return;
    }
    else{ // otherwise, run the paintevent
        QMainWindow::paintEvent(event);
    }

}

void knife::keyPressEvent(QKeyEvent *event){

    switch(event->key()){ // different cases when different keys are pressed
    case Qt::Key_Right: // move right 20 units
        x+=20; break;
    case Qt::Key_Left: // move left 20 units
        x-=20; break;
    case Qt::Key_Up: // move up 20 units
        y-=20; break;
    case Qt::Key_Down: // move down 20 units
        y+=20; break;
    case Qt::Key_Space: // chop
        if(abs(x-sx)<=50 && abs(y-sy)<=50){ // if the knife and sushi are close enough to each other
            error=false;
            if(c<10){ // if sushi has been cut less than 10 times, move the sushi somewhere else to be chopped
                sx=qrand()%600+1;
                sy=qrand()%(200-40)+40;
                ++c;
                emit CutSushi();
                break;
            }
            else{ // otherwise, hide the sushi and knife and emit the finish_chopping signal
                hidesushi();
                emit finish_chopping();
                break;
            }
        }
        else{//otherwise, set the error to true and display that the knife is too far from the sushi
            if (c<10) {
                error=true;
                ++c;
                emit MissedSushi();
                break; }
            else {
                hidesushi();
                emit finish_chopping();
                break;
            }
        }
    default:
        QMainWindow::keyPressEvent(event);
    }
    QCoreApplication::processEvents();
    repaint();
    return;
}

