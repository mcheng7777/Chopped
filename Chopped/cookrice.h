#ifndef COOKRICE_H
#define COOKRICE_H


#include <QWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QBoxLayout>
#include <QFontDatabase>
#include <QLabel>
#include <QLinearGradient>
#include "movingitem.h"


/**
 * @brief The CookRice class
 * creates the layout for the rice cooking game
 * This will be one of the challenges in the game
 * This class will have functions that cook rice
 */

class CookRice : public QMainWindow {
    Q_OBJECT
public:
    /**
     * @brief constructor for the cooking rice window
     * @param parent - nullptr
    */
    explicit CookRice(QWidget* parent = nullptr);

    /**
     * @brief destructor for the cooking rice window
    */
    ~CookRice() {}

    QPushButton* rnextgame;
    MovingItem* movingbar;

public slots:
    /**
     * @brief make the next push button appear at the end of the game
    */
    void makeButtonAppear();

    /**
     * @brief start the moving bar across the window
    */
    void moveItem();

private:
    QWidget* riceWindow;
    QVBoxLayout* riceLayout;
    QPushButton* start;
    QHBoxLayout* movingLayout;


};

#endif // COOKRICE_H
