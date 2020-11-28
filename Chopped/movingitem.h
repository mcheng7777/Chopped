#ifndef MOVINGITEM_H
#define MOVINGITEM_H

#include <QGraphicsItem>
#include <QPainter>
#include <QWidget>
#include <QGraphicsItemAnimation>
#include <QGraphicsView>
#include <QTimeLine>
#include <QGridLayout>
#include <QMainWindow>
#include <QLabel>
#include <QPropertyAnimation>
#include <QKeyEvent>
#include <QCoreApplication>
#include <QApplication>

/**
 * @brief The MovingItem class
 * creates the moving widget that will be part of the cooking rice game
 * includes keyPressEvent for stopping the moving widget
 * calculates the score based on where the user stops the widget
 */
class MovingItem : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief constructor for the moving widget
     * @param parent - nullptr
    */
    MovingItem(QWidget* parent = nullptr);

    /**
     * @brief destructor for the moving widget
    */
    ~MovingItem() {}

    /**
     * @brief key press event for stopping the animation
    */
    void keyPressEvent(QKeyEvent* event);

    /**
     * @brief gets the score
       @return an int
     */
    int get_score() const;

    /**
     * @brief starts the animation
    */
    void startMovement();

signals:
    /**
     * @brief signal when space bar is pressed
    */
    void keyIsPressed();
public slots:

    /**
     * @brief update the score
    */
    void UpdateScore();

    /**
     * @brief update the position that the user stopped the moving widget
    */
    void UpdatePos();



private:
    QLabel* line;
    QPropertyAnimation* animation;
    QPoint n;
    int ricescore;

};

#endif  // MOVINGITEM_H
