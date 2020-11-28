// this is the home window of the game
// it will be the first index of the QStackedWidget
// in the following games, the user will return to this page if they do not pass

#ifndef OPTIONS_H
#define OPTIONS_H
#include "mainwindow.h"
#include <QWidget>
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QLayout>
#include <QFontDatabase>

/**
 * @brief The Options class
 * displays the options for dishes the user can select from
 * in this case, there is only one option: sushi
 */
class Options: public QMainWindow {
    Q_OBJECT
public:
    /**
     * @brief constructor for the options window
     * @param parent - nullptr
    */
    explicit Options(QWidget* parent = nullptr);

    /**
     * @brief destructor for the options window
    */
    ~Options() {}

    QPushButton* item;

private:
    QWidget* optionsWindow;
};

#endif // OPTIONS_H

