

#ifndef INGREDIENTS_H
#define INGREDIENTS_H


#include <QMainWindow>
#include <QLabel>
#include <QWidget>
#include <QLayout>
#include <QPushButton>
#include <QPainter>
#include <QFontDatabase>
#include <QFont>
#include <QDebug>
#include <QPixmap>
#include <QPalette>
#include <QIcon>
#include <vector>
#include <QTime>
#include <QTimer>
#include <QKeyEvent>

/**
 * @brief The Ingredients class
 * creates the layout for the ingredients picking game
 * This will be one of the challenges in the game
 * This class will have functions that choose ingredients
 */
class Ingredients : public QMainWindow{
    Q_OBJECT
public:
    /**
     * @brief Constructor for the ingredients game
     * @param parent - nullptr
     */
    explicit Ingredients(QWidget *parent = nullptr);

    /**
     * @brief Destructor for the ingredients game
     */
    ~Ingredients(){}



    /**
     * @brief gets the score of the game
       @return int of the score
    */
    int get_score() const;

    QPushButton* next;

public slots:
    /**
     * @brief starts the timer for the game
    */
    void TimerStart();

    /**
     * @brief handles when the correct ingredient is chosen
    */
    void correct();

    /**
     * @brief handles when the incorrect ingredient is chosen
    */
    void incorrect();

    /**
     * @brief handles when the last correct ingredient is chosen
    */
    void correct_end();

    /**
     * @brief handles when the last incorrect ingredient is chosen
    */
    void incorrect_end();

    /**
     * @brief handles when the timer is up
     */
    void stopTimer();

private:
    QPushButton* start;
    std::vector<QPushButton*> b;
    QHBoxLayout* picLayout;
    QVBoxLayout* ingredientsLayout;
    QLabel* message;
    int leftpic=0;
    int rightpic=1;
    int score=0;
    QTimer* timer;
    QLabel* instruction;


};

#endif // INGREDIENTS_H
