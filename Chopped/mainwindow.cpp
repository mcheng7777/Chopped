#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
   QMainWindow(parent),
   ui(new Ui::MainWindow)
{
   ui->setupUi(this);

   setWindowTitle("Welcome to Chopped");
   setFixedSize(900,700);

   // set the background
   // image obtained from: https://wall.alphacoders.com/big.php?i=46709
   this->setStyleSheet("QWidget{background-image: url(:/pictures/background.jpg);}");

   play = new QPushButton("Sound on");
   stop = new QPushButton("Mute");
   QHBoxLayout* musicLayout = new QHBoxLayout;
   musicLayout->addWidget(play);
   musicLayout->addWidget(stop);

   music = new QMediaPlayer();
   music->setMedia(QUrl("qrc:/sound/In_the_restaurant.mp3"));

   QObject::connect(play, &QPushButton::clicked, this, &MainWindow::playMusic);
   QObject::connect(stop, &QPushButton::clicked, this, &MainWindow::stopMusic);


   // Set font
   QFontDatabase::addApplicationFont(":/fonts/LobsterTwo-Bold.ttf");
   QFont font = QFont("Lobster Two", 70, 1);

   // title label
   QLabel* title = new QLabel("Chopped");
   title->setFont(font);


   // Create a layout and center the layout
   QVBoxLayout* layout = new QVBoxLayout;
   layout->addLayout(musicLayout);
   layout->addWidget(title);
   layout->setAlignment(Qt::AlignCenter);

   // create a widget wiht the layout and set this to be the central widget of the window
   QWidget* center = new QWidget;
   center->setLayout(layout);
   setCentralWidget(center);

   // Create a push button that will start the game
   start = new QPushButton("Start");
   layout->addWidget(start);
   start->setFocusPolicy(Qt::ClickFocus);

   // Create a quit button
   QPushButton* quit = new QPushButton("Quit");
   QObject::connect(quit, &QPushButton::clicked, this, &QApplication::quit);
   layout->addWidget(quit);


   // Add picture of chef
   // picture obtained from: https://newvitruvian.com/explore/sushi-clipart-sushi-chef/
   QPixmap chef(":/pictures/chef.jpg");
   QLabel* label_pic = new QLabel;
   label_pic->setPixmap(chef);
   layout->addWidget(label_pic);

}

void MainWindow::resizeEvent(QResizeEvent* evt)
{
   QPixmap bkgnd(":/pictures/background.jpg");                 //Load pic
   bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio);   //set scale of pic to match the window
   QPalette p = palette();                                                    //copy current, not create new
   p.setBrush(QPalette::Background, bkgnd);                   //set the pic to the background
   setPalette(p);                                                                 //show the background pic
   QMainWindow::resizeEvent(evt);
}

void MainWindow::playMusic()
{
    music->play();
}

void MainWindow::stopMusic()
{
    music->stop();
}


MainWindow::~MainWindow()
{
   delete ui;
}

