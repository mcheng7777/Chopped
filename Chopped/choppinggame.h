



#ifndef CHOPPINGGAME_H
#define CHOPPINGGAME_H

#include <QLabel>
#include <QFont>
#include <QFontDatabase>
#include <QPixmap>
#include <QPalette>
#include <QPainter>
#include <QPaintEvent>
#include <QPaintEngine>
#include <QWidget>
#include <QStackedWidget>
#include <QMainWindow>
#include <QBoxLayout>
#include <QPushButton>
#include <QKeyEvent>
#include <QTimer>
#include <QLayout>

/**
 * @brief The knife class controls the knife and sashimi paintEvents
 */
class knife;

/**
 * @brief The ChoppingGame class
 * creates the layout for the chopping game
 * This will be one of the challenges in the game
 * This class will have functions that chop sushi
 */
class ChoppingGame : public QMainWindow  {
   Q_OBJECT
public:
   /**
    * @brief Constructor for the chopping game
    * @param parent - nullptr
    */
   explicit ChoppingGame(QWidget* parent = nullptr);

    /**
     * @brief Destructor for the chopping game
     */
   ~ChoppingGame() {}

    /**
     * @brief gets the score of the chopping game
     * @return int score
     */
    int get_score() const;

    /**
     * start the timer for the chopping game
     */
    void TimerStart();

    /**
     * @brief when the user presses the 0 key, start the timer and the game
     * @param event - QKeyEvent
     */
    void keyPressEvent(QKeyEvent* event);

    QPushButton* cnextgame;

public slots:

    /**
     * @brief makes the button that goes to the next page appear
     */
    void make_button_appear();

    /**
     * @brief stops the timer and ends the game
     */
    void TimerStop();

    /**
     * @brief adds one to the score if the user chops the fish
     */
    void add_to_score();

    /**
     * @brief subtracts one from the score if the user misses
     */
    void minus_score();

private:
    double x,y;
    QHBoxLayout* choppingLayout;
    QGridLayout* grid;
    knife* k;
    int score;
    QVBoxLayout* mainLayout;
    QWidget* test;
    QTimer* timer;
    QLabel* final;
    QString final_score;
    QLabel* instruction;
};



/**
 * @brief The knife class controls the knife and sashimi paintEvents and keyPressEvents
 */
class knife : public QMainWindow{
    Q_OBJECT
public:

    /**
     * @brief Constructor with paramters
     */
    explicit knife(QWidget* parent=nullptr);

    /**
     * @brief Destructor
     */
    ~knife(){}

    /**
     * @brief creates the knife and sushi
     * @param event - QPaintEvent*
     */
    void paintEvent(QPaintEvent* event);

    /**
     * @brief moves the knife and sushi
     * @param event - QKeyEvent*
     */
    void keyPressEvent(QKeyEvent* event);

    /**
     * @brief shows the sushi
    */
    void showsushi();

    /**
     * @brief hides the sushi
    */
    void hidesushi();

signals:
    /**
     * @brief signal when the chopping is finished
    */
    void finish_chopping();

    /**
     * @brief signal when the sushi is cut to update score
     */
    void CutSushi();

    /**
     * @brief signal when the user misses the sushi to update score
     */
    void MissedSushi();

private:
    int x,y;
    int sx,sy;
    bool m_showsushi;
    int c;
    bool error;

};

#endif // CHOPPINGGAME_H


