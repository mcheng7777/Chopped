#ifndef FINAL_H
#define FINAL_H

#include <QMainWindow>
#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QFont>
#include <QFontDatabase>
#include <QPushButton>

/**
 * @brief The Final class
 * final page
 * displays the winner of the game
 */
class Final : public QMainWindow {
    Q_OBJECT
public:
    /**
     * @brief constructor for the final window of the game
     * @param parent - nullptr
     */
    explicit Final(QWidget* parent = nullptr);

    /**
      * @brief destructor for the final window of the game
      */
    ~Final() {}

    QPushButton* quit;
    QLabel* congrats;
private:
    QWidget* finalWindow;

};

#endif // FINAL_H
