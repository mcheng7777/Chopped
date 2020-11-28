#ifndef CONGRATS_H
#define CONGRATS_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QFontDatabase>
#include <QPushButton>
#include <QBoxLayout>

/**
 * @brief The Congrats class
 * displays the end page after each player's turn
 * calculates and displays each player's score
 */
class Congrats : public QMainWindow
{
    Q_OBJECT
public:

    /**
     * @brief constructor for the congrats window
     * @param parent - nullptr
    */
    explicit Congrats(QWidget* parent = nullptr);

    /**
     * @brief destructor for the congrats window
    */
    ~Congrats() {}

    QPushButton* endGame;
    QPushButton* generateScore;
    QVBoxLayout* congratsLayout;
private:
    QWidget* congratsWindow;
};

#endif // CONGRATS_H

