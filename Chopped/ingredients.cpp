
#include "ingredients.h"
#include <QCoreApplication>

Ingredients::Ingredients(QWidget* parent) : QMainWindow(parent), message(new QLabel()), timer(new QTimer(this)), instruction(new QLabel("Timer will start upon clicking Start")){

   setFixedSize(900,700);

   // create title and set font
   QLabel* ingredientsTitle = new QLabel("Ingredients Game");
   QFontDatabase::addApplicationFont(":/fonts/gooddog.otf");
   QFont titlefont("GoodDog", 80, 1);
   ingredientsTitle->setFont(titlefont);
   ingredientsTitle->setAttribute(Qt::WA_TranslucentBackground);

   // create layout
   ingredientsLayout = new QVBoxLayout();
   ingredientsLayout->addWidget(ingredientsTitle);
   ingredientsLayout->setAlignment(Qt::AlignCenter);
   // create layout for the displayed ingredients
   picLayout = new QHBoxLayout;
   ingredientsLayout->addLayout(picLayout);

   // create widget for central widget
   QWidget* center = new QWidget;
   center->setLayout(ingredientsLayout);
   setCentralWidget(center);

   // create an empty label that will have text appear when the user inputs text
   message->setAttribute(Qt::WA_TranslucentBackground);
   message->setAlignment(Qt::AlignCenter);

   // create a label with some short instructions to begin
   instruction->setAttribute(Qt::WA_TranslucentBackground);
   instruction->setAlignment(Qt::AlignCenter);
   ingredientsLayout->addWidget(instruction);

   // create push button that goes to the next page
   next = new QPushButton("next");

   // create button to start game
   start = new QPushButton("start");
   ingredientsLayout->addWidget(start);
   QObject::connect(start, &QPushButton::clicked, this, &Ingredients::TimerStart);

   //add a background picture to the ingredients window
   // picture obtained from: https://www.pinterest.com/pin/535295105693051879/
   this->setStyleSheet("QWidget{background-image: url(:/pictures/ingredients_background.jpeg);}");


   // create all the pushbutton that contains pictures
   QPushButton* button1 = new QPushButton;
   QPushButton* button2 = new QPushButton;
   QPushButton* button3 = new QPushButton;
   QPushButton* button4 = new QPushButton;
   QPushButton* button5 = new QPushButton;
   QPushButton* button6 = new QPushButton;
   QPushButton* button7 = new QPushButton;
   QPushButton* button8 = new QPushButton;
   QPushButton* button9 = new QPushButton;
   QPushButton* button10 = new QPushButton;
   QPushButton* button11 = new QPushButton;
   QPushButton* button12 = new QPushButton;
   QPushButton* button13 = new QPushButton;
   QPushButton* button14 = new QPushButton;
   QPushButton* button15 = new QPushButton;
   QPushButton* button16 = new QPushButton;

   // pushback all buttons the pushbutton* vector b
   b.push_back(button1);
   b.push_back(button2);
   b.push_back(button3);
   b.push_back(button4);
   b.push_back(button5);
   b.push_back(button6);
   b.push_back(button7);
   b.push_back(button8);
   b.push_back(button9);
   b.push_back(button10);
   b.push_back(button11);
   b.push_back(button12);
   b.push_back(button13);
   b.push_back(button14);
   b.push_back(button15);
   b.push_back(button16);

   /* Add pictures and set icons of the buttons to the respective pictures*/

   // add picture of goldfish
   // picture obtained from https://108grocery.com/1175/Pepperidge-Farm-Snack-Baked-Cheddar-Goldfish-Crackers-30-oz-Carton/
   QPixmap goldfish(":/pictures/goldfish.jpeg");
   QIcon ButtonIcon(goldfish);
   button1->setIcon(ButtonIcon);
   button1->setStyleSheet("background:transparent");
   button1->setIconSize(goldfish.size());


   // add picture of packaged fish
   // picture obtained from https://www.coopathome.ch/en/supermarket/meat-fish/packaged-fish/packaged-fresh-fish/salmon-trout-fillets-3-pieces-ca/p/4479314
   QPixmap packaged_fish(":/pictures/packaged_fish.png");
   QIcon ButtonIcon2(packaged_fish);
   button2->setIcon(ButtonIcon2);
   button2->setStyleSheet("background:transparent");
   button2->setIconSize(packaged_fish.size());


   // add picture of seaweed
   // https://www.amazon.com/Dried-Seaweed-Sheets_Korean-Roasted-Healthy/dp/B00VRT8OXS
   QPixmap seaweed(":/pictures/seaweed.jpg");
   QIcon ButtonIcon3(seaweed);
   button3->setStyleSheet("background:transparent");
   button3->setIconSize(goldfish.size());
   button3->setIcon(ButtonIcon3);

   // add picture of tortilla
   // https://www.walmart.com/ip/Mission-Soft-Taco-Flour-Tortillas-10-Count/10309357
   QPixmap tortilla(":/pictures/tortilla.jpeg");
   QIcon ButtonIcon4(tortilla);
   button4->setStyleSheet("background:transparent");
   button4->setIconSize(goldfish.size());
   button4->setIcon(ButtonIcon4);

   // add picture of mashed potatoes
   //https://idahoan.com/products/idahoan-original-mashed-potatoes/
   QPixmap mashed_potatoes(":/pictures/mashed_potatoes.png");
   QIcon ButtonIcon5(mashed_potatoes);
   button5->setStyleSheet("background:transparent");
   button5->setIconSize(goldfish.size());
   button5->setIcon(ButtonIcon5);

   // add picture of sushi rice bag
   //http://www.shopwell.com/kokuho-rose-rice-the-unique-new-variety/rice-other-grains/p/7323402009
   QPixmap sushi_rice(":/pictures/sushi_rice.jpg");
   QIcon ButtonIcon6(sushi_rice);
   button6->setStyleSheet("background:transparent");
   button6->setIconSize(goldfish.size());
   button6->setIcon(ButtonIcon6);

   // add picture of broccoli
   //https://hosstools.com/product/arcadia-broccoli/
   QPixmap broccoli(":/pictures/broccoli.jpg");
   QIcon ButtonIcon7(broccoli);
   button7->setStyleSheet("background:transparent");
   button7->setIconSize(goldfish.size());
   button7->setIcon(ButtonIcon7);

   // add picture of avocado
   //https://www.californiaavocado.com/blog/how-to-ripen-an-avocado
   QPixmap avocado(":/pictures/avocado.png");
   QIcon ButtonIcon8(avocado);
   button8->setStyleSheet("background:transparent");
   button8->setIconSize(goldfish.size());
   button8->setIcon(ButtonIcon8);

   // add picture of sriracha
   //https://ya-webdesign.com/explore/sriracha-bottle-png/
   QPixmap sriracha(":/pictures/sriracha.png");
   QIcon ButtonIcon9(sriracha);
   button9->setStyleSheet("background:transparent");
   button9->setIconSize(goldfish.size());
   button9->setIcon(ButtonIcon9);

   // add picture of soy sauce
   //https://www.americastestkitchen.com/taste_tests/1711-soy-sauce
   QPixmap soy_sauce(":/pictures/soysauce.png");
   QIcon ButtonIcon10(soy_sauce);
   button10->setStyleSheet("background:transparent");
   button10->setIconSize(goldfish.size());
   button10->setIcon(ButtonIcon10);

   //http://pngimg.com/imgs/tableware/fork/
   QPixmap fork(":/pictures/fork.png");
   QIcon ButtonIcon11(fork);
   button11->setStyleSheet("background:transparent");
   button11->setIconSize(goldfish.size());
   button11->setIcon(ButtonIcon11);

   //http://www.pngpix.com/download/chopsticks-png-transparent-image-2
   QPixmap chopsticks(":/pictures/chopsticks.png");
   QIcon ButtonIcon12(chopsticks);
   button12->setStyleSheet("background:transparent");
   button12->setIconSize(goldfish.size());
   button12->setIcon(ButtonIcon12);


   //https://www.clipartmax.com/middle/m2i8N4H7N4b1K9K9_cucumber-clipart-small-cucumber-white-background/
   QPixmap cucumber(":/pictures/cucumber.png");
   QIcon ButtonIcon13(cucumber);
   button13->setStyleSheet("background:transparent");
   button13->setIconSize(goldfish.size());
   button13->setIcon(ButtonIcon13);

   //https://dlpng.com/png/56851
   QPixmap zucchini(":/pictures/zucchini.png");
   QIcon ButtonIcon14(zucchini);
   button14->setStyleSheet("background:transparent");
   button14->setIconSize(goldfish.size());
   button14->setIcon(ButtonIcon14);

   //https://www.meijer.com/product/grocery/seafood/crab/meijer-imitation-crab-legs-8-oz/t1/t1-865/t2/t2-10125/t3/t3-814/4125018911.uts
   QPixmap crabmeat(":/pictures/crabmeat.png");
   QIcon ButtonIcon15(crabmeat);
   button15->setStyleSheet("background:transparent");
   button15->setIconSize(goldfish.size());
   button15->setIcon(ButtonIcon15);

   //https://www.walmart.com/ip/Fresh-Thin-Sliced-Boneless-Skinless-Chicken-Breasts-2-0-3-0-lb/49932958
   QPixmap chicken(":/pictures/chicken.png");
   QIcon ButtonIcon16(chicken);
   button16->setStyleSheet("background:transparent");
   button16->setIconSize(goldfish.size());
   button16->setIcon(ButtonIcon16);

   // connections for all buttons
   QObject::connect(button1, &QPushButton::clicked, this, &Ingredients::incorrect);
   QObject::connect(button2, &QPushButton::clicked, this, &Ingredients::correct);
   QObject::connect(button3, &QPushButton::clicked, this, &Ingredients::correct);
   QObject::connect(button4, &QPushButton::clicked, this, &Ingredients::incorrect);
   QObject::connect(button5, &QPushButton::clicked, this, &Ingredients::incorrect);
   QObject::connect(button6, &QPushButton::clicked, this, &Ingredients::correct);
   QObject::connect(button7, &QPushButton::clicked, this, &Ingredients::incorrect);
   QObject::connect(button8, &QPushButton::clicked, this, &Ingredients::correct);
   QObject::connect(button9, &QPushButton::clicked, this, &Ingredients::incorrect);
   QObject::connect(button10, &QPushButton::clicked, this, &Ingredients::correct);
   QObject::connect(button11, &QPushButton::clicked, this, &Ingredients::incorrect);
   QObject::connect(button12, &QPushButton::clicked, this, &Ingredients::correct);
   QObject::connect(button13, &QPushButton::clicked, this, &Ingredients::correct);
   QObject::connect(button14, &QPushButton::clicked, this, &Ingredients::incorrect);
   QObject::connect(button15, &QPushButton::clicked, this, &Ingredients::correct_end);
   QObject::connect(button16, &QPushButton::clicked, this, &Ingredients::incorrect_end);
}


int Ingredients::get_score() const{
    return score;
}

void Ingredients::correct(){
    ++score;
    delete b[leftpic];
    b[leftpic]=nullptr;
    delete b[rightpic];
    b[rightpic]=nullptr;

    leftpic=leftpic+2;
    rightpic=rightpic+2;
    if(b[leftpic]!=nullptr){
        picLayout->addWidget(b[leftpic]);
    }
    if(b[rightpic]!=nullptr){
        picLayout->addWidget(b[rightpic]);
    }
    message->setText("+1");
    ingredientsLayout->addWidget(message);


}

void Ingredients::incorrect(){
    delete b[leftpic];
    b[leftpic]=nullptr;
    delete b[rightpic];
    b[rightpic]=nullptr;

    leftpic=leftpic+2;
    rightpic=rightpic+2;
    if(b[leftpic]!=nullptr){
        picLayout->addWidget(b[leftpic]);
    }
    if(b[rightpic]!=nullptr){
        picLayout->addWidget(b[rightpic]);
    }

    message->setText("+0");
    ingredientsLayout->addWidget(message);

}

void Ingredients::correct_end(){
    ++score;
    delete b[leftpic];
    b[leftpic]=nullptr;
    delete b[rightpic];
    b[rightpic]=nullptr;
    stopTimer();
    message->setText("+1");
    ingredientsLayout->addWidget(message);
}

void Ingredients::incorrect_end() {
    delete b[leftpic];
    b[leftpic]=nullptr;
    delete b[rightpic];
    b[rightpic]=nullptr;
    stopTimer();
    message->setText("+0");
    ingredientsLayout->addWidget(message);
}

//void Ingredients::keyPressEvent(QKeyEvent* event){

//    switch(event->key()){
//    case Qt::Key_0:{ // when the 0 key is pressed, the timer starts, and the game starts
//        qDebug() << "Call";
//        TimerStart();
//        picLayout->addWidget(b[leftpic]);
//        picLayout->addWidget(b[rightpic]);
//        instruction->hide();
//        break;
//    }
//    default:
//        QMainWindow::keyPressEvent(event);
//    }
//    QCoreApplication::processEvents();
//    return;
//}

void Ingredients::TimerStart(){
    timer->setInterval(10000);
    QObject::connect(timer,&QTimer::timeout, this, &Ingredients::stopTimer);
    timer->start(10000);

    picLayout->addWidget(b[leftpic]);
    picLayout->addWidget(b[rightpic]);
    instruction->hide();
    start->hide();
}

void Ingredients::stopTimer(){
    timer->stop();
    delete b[leftpic];
    b[leftpic]=nullptr;
    delete b[rightpic];
    message->setText("Time is Up!");
    QString point = QString::number(get_score());
    QLabel* points = new QLabel("you got " + point + "/8 " + "words correct");
    points->setAttribute(Qt::WA_TranslucentBackground);
    points->setAlignment(Qt::AlignCenter);
    ingredientsLayout->addWidget(points);
    ingredientsLayout->addWidget(next);
    next->show();




}
