#include "movingitem.h"
#include <QDebug>

MovingItem::MovingItem(QWidget* parent) : QWidget(parent)
{

    // create the line that will be moving back and forth
    line = new QLabel;
    line->setFixedSize(10,50);
    line->setStyleSheet("QLabel { background-color : black; }");

    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(line);
    setLayout(layout);
    setFixedSize(900,50);

    // make the line an animation that will be moving for 10 seconds
    animation = new QPropertyAnimation(line, "geometry");
    animation->setDuration(10000);

    for (int i = 0; i < 11; ++i) {  // for the duration of time alternate positions between the far right and far left
        int x;
        if (i % 2 == 0)
            x = 0;
        else {
            x = 900;
        }
        animation->setKeyValueAt(0.1*i, QRect(x, 0, 100, 30));   // move position of the line

    }

    // connect pressing key signal to updating the position of the line
    QObject::connect(this, &MovingItem::keyIsPressed, this, &MovingItem::UpdatePos);

    // connect pressing key signal to updating the score associated with the position
    QObject::connect(this, &MovingItem::keyIsPressed, this, &MovingItem::UpdateScore);


}

void MovingItem::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()) {
        case Qt::Key_Space: {  // if the space bar is pressed, emit signal and stop animation
            emit keyIsPressed();
            animation->stop();

        }

    }

    return QWidget::keyPressEvent(event);

}

int MovingItem::get_score() const
{
    return ricescore;
}

void MovingItem::startMovement(){
    animation->start();
}

void MovingItem::UpdateScore() {
    if (n.x() < 225 || n.x() >= 623) ricescore = 5;  // if the user stops the line in the red
    else if ((225 <= n.x() && n.x() <= 412) | (426 <= n.x() && n.x() < 623)) ricescore = 15; // if the user stops the line in the yellow
    else if (412 < n.x() && n.x() < 426) ricescore = 25;  // if the user stops the line in the green
}

void MovingItem::UpdatePos()
{
   n = line->pos();
}


