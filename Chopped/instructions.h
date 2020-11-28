// this window will appear before the start of each game to provide instructions on how to play/pass

#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H


#include <QWidget>
#include <QMainWindow>
#include <QLabel>
#include <QLayout>
#include <QFontDatabase>
#include <QPushButton>


/**
 * @brief The Instructions class
 * displays specific instructions for each minigame
 */
class Instructions : public QMainWindow  {
    Q_OBJECT
public:
    /**
     * @brief constructor for the Instructions window
     * @param parent - nullptr
    */
    explicit Instructions(QWidget* parent = nullptr);

    /**
     * @brief destructor for the Instructions window
    */
    ~Instructions() {}

    QPushButton* next;
    QLabel* instruct;

private:
    QWidget* instructionsWindow;
};

#endif // INSTRUCTIONS_H


