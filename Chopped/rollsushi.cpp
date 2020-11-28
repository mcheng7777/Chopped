#include "rollsushi.h"

RollSushi::RollSushi(QWidget *parent) :
    QMainWindow(parent)
{
    // the random string generator generates different strings each time
    QTime now= QTime::currentTime() ;
    qsrand( now.msec() );
    timer = new QTimer(this);

    sushiWindow = new QWidget;
    setFixedSize(900, 700);

    // create a title label, set the font and background
    QLabel* sushiTitle = new QLabel("Roll the Sushi");
    QFontDatabase::addApplicationFont(":/fonts/gooddog.otf");
    QFont titlefont("GoodDog", 80, 1);
    sushiTitle->setFont(titlefont);
    sushiTitle->setAttribute(Qt::WA_TranslucentBackground);

    //generate random string vector
    generateRandVec();

    // create a label with some short instructions to begin
    instruction = new QLabel("Press 0 to begin");
    instruction->setAttribute(Qt::WA_TranslucentBackground);
    instruction->setAlignment(Qt::AlignCenter);

    // create a label with the random string
    randomString = new QLabel(vec[0]);
    randomString->setAttribute(Qt::WA_TranslucentBackground);
    randomString->setAlignment(Qt::AlignCenter);

    // create a line edit for the user to input characters
    edit = new QLineEdit();
    edit->setFixedSize(700,30);
    edit->setAlignment(Qt::AlignCenter);

    // create a layout for the window
    sushiLayout = new QVBoxLayout(sushiWindow);
    sushiTitle->setAlignment(Qt::AlignCenter);
    sushiLayout->addWidget(sushiTitle);
    sushiLayout->addWidget(instruction);


    // create a grid layout for the images that will appear when the user types the right string
    sushiSteps = new QGridLayout;
    sushiSteps->setSpacing(0);
    images = new QWidget;
    images->setLayout(sushiSteps);
    images->setFixedSize(680,500);
    images->setAttribute(Qt::WA_TranslucentBackground);

    // create a push button for the dish that will start the game
    finish = new QPushButton("Finish Bento Box");

    // create an empty label that will have text appear when the user inputs text
    message = new QLabel("");
    message->setAttribute(Qt::WA_TranslucentBackground);
    message->setAlignment(Qt::AlignCenter);

    sushiLayout->setAlignment(Qt::AlignCenter);

    // create a widget with the layout and set this to be the central widget of the window
    QWidget* center = new QWidget;
    center->setLayout(sushiLayout);
    setCentralWidget(center);

    // set the background
    // picture obtained from https://www.istockphoto.com/dk/photos/kitchen-background?mediatype=photography&phrase=kitchen%20background&sort=mostpopular
    this->setStyleSheet("QWidget{background-image: url(:/pictures/kitchen_background.jpg);}");


    // connect pressing the enter key in the qlineedit to updating the string that stores the text inputed
    QObject::connect(edit, &QLineEdit::returnPressed, this, &RollSushi::updateString);

    // make the vector that will store the pictures of sushi steps
    generateSteps();
}

QString RollSushi::generateRandString()
{
    const QString possibleCharacters("abcdefghijklmnopqrstuvwxyz");
    const int randomStringLength = 6;

    QString randomString;
    for(int i=0; i<randomStringLength; ++i)   // create a random string of length 6
    {
        int index = qrand() % possibleCharacters.length();
        QChar nextChar = possibleCharacters.at(index);
        randomString.append(nextChar);
    }
    return randomString;
}

void RollSushi::generateRandVec()
{
    for (int i = 0; i < 13; ++i) {  // create a vector of randomly generated strings
        QString randword = generateRandString();
        vec.append(randword);
    }
}

const QString RollSushi::getstr() {
    return string;
}

void RollSushi::updateString() {
    edit->blockSignals(true);
    string = edit->text();  // get the string that the user inputed in the line edit
    if (string == vec[vec_index]){   // if the input matches the randomly generated string that appeared on the window
        edit->selectAll();
        edit->clear();
        message->setText("+1");
        sushiLayout->addWidget(message);
        ++score;

        if (vec_index == 4 || vec_index == 8) {++rows; columns = 0;}
        sushiSteps->addWidget(steps[vec_index],rows, columns);
        ++columns;
        ++vec_index;

        if (vec_index == 12) {
            stopTimer();
        }
        randomString->setText(vec[vec_index]);    // go to the next randomly generated string in the vector
        randomString->update();
    }
    else {  // if the input did not match the generated string, send an error message and try again
        message->setText("Wrong characters, try again");
        sushiLayout->addWidget(message);
        edit->clear();

    }

    edit->blockSignals(false);

}

void RollSushi::TimerStart()
{
    timer->setInterval(30000);   // set the timer for 20 seconds

    // at the end of the interval, stop the timer and end the game
    QObject::connect(timer, &QTimer::timeout, this, &RollSushi::stopTimer);
    timer->start(30000);

}

void RollSushi::stopTimer()
{
    timer->stop();
    edit->hide();
    randomString->hide();
    instruction->hide();
    message->setText("Time is Up!");

    QString point = QString::number(get_score());  // get the score
    QLabel* points = new QLabel("You got " + point + "/12 "+ "words correct");
    points->setAlignment(Qt::AlignCenter);
    points->setAttribute(Qt::WA_TranslucentBackground);

    sushiLayout->addWidget(points);
    sushiLayout->addWidget(finish);
    edit->clearFocus();   // make sure the user cannot input anything else into the line edit
    finish->setFocusPolicy(Qt::ClickFocus);

}

void RollSushi::keyPressEvent(QKeyEvent* event)
{

    switch(event->key()) {

    case Qt::Key_0: {   // when the user presses the '0' key start the timer and begin typing in the line edit
        TimerStart();
        sushiLayout->addWidget(randomString);
        sushiLayout->addWidget(edit);
        instruction->setText("Press Enter after each completed word \n\nType string below: ");
        sushiLayout->addWidget(images);
        edit->setFocus();

    }
    }
    return QWidget::keyPressEvent(event);

}

int RollSushi::get_score() const
{
    return score;
}


void RollSushi::generateSteps() {
    QWidget* one = new QWidget;
    QWidget* two = new QWidget;
    QWidget* three = new QWidget;
    QWidget* four = new QWidget;
    QWidget* five = new QWidget;
    QWidget* six = new QWidget;
    QWidget* seven = new QWidget;
    QWidget* eight = new QWidget;
    QWidget* nine = new QWidget;
    QWidget* ten = new QWidget;
    QWidget* eleven = new QWidget;
    QWidget* twelve = new QWidget;

    // picture is obtained from: s://japan.recipetineats.com/sushi-rolls-norimaki/

    one->setStyleSheet("QWidget{background-image: url(:/pictures/step1.jpg);}");
    one->setFixedSize(150,150);
    two->setStyleSheet("QWidget{background-image: url(:/pictures/step2.jpg);}");
    two->setFixedSize(150,150);
    three->setStyleSheet("QWidget{background-image: url(:/pictures/step3.jpg);}");
    three->setFixedSize(150,150);
    four->setStyleSheet("QWidget{background-image: url(:/pictures/step4.jpg);}");
    four->setFixedSize(150,150);
    five->setStyleSheet("QWidget{background-image: url(:/pictures/step5.jpg);}");
    five->setFixedSize(150,150);
    six->setStyleSheet("QWidget{background-image: url(:/pictures/step6.jpg);}");
    six->setFixedSize(150,150);
    seven->setStyleSheet("QWidget{background-image: url(:/pictures/step7.jpg);}");
    seven->setFixedSize(150,150);
    eight->setStyleSheet("QWidget{background-image: url(:/pictures/step8.jpg);}");
    eight->setFixedSize(150,150);
    nine->setStyleSheet("QWidget{background-image: url(:/pictures/step9.jpg);}");
    nine->setFixedSize(150,150);
    ten->setStyleSheet("QWidget{background-image: url(:/pictures/step10.jpg);}");
    ten->setFixedSize(150,150);
    eleven->setStyleSheet("QWidget{background-image: url(:/pictures/step11.jpg);}");
    eleven->setFixedSize(150,150);
    twelve->setStyleSheet("QWidget{background-image: url(:/pictures/step12.jpg);}");
    twelve->setFixedSize(150,150);

    // add widgets with pictures to the vector
    steps.append(one);
    steps.append(two);
    steps.append(three);
    steps.append(four);
    steps.append(five);
    steps.append(six);
    steps.append(seven);
    steps.append(eight);
    steps.append(nine);
    steps.append(ten);
    steps.append(eleven);
    steps.append(twelve);
}



