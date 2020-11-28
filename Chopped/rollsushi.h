// This will be one of the challenges in the game
// this class will have functions that make the sushi for the bento box
// this game will be displayed in one widget within a QStackedWidget
// if the user passes this game, they will go to the next game displayed in a different widget within the QStackedWidget
// if they fail, they will return to the options window (index 0 of the QStackedWidget)


#ifndef ROLLSUSHI_H
#define ROLLSUSHI_H

#include <QWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QFontDatabase>
#include <QLabel>
#include <QBoxLayout>
#include <QVector>
#include <QDebug>
#include <QLineEdit>
#include <QString>
#include <QTextEdit>
#include <QTime>
#include <QTimer>
#include <QKeyEvent>

/**
 * @brief The RollSushi class
 * creates the layout for the sushi rolling game
 * This will be one of the challenges in the game
 * This class will have functions that roll sushi
 */
class RollSushi : public QMainWindow  {
    Q_OBJECT
public:
    /**
     * @brief constructor for the rolling sushi window
     * @param parent - nullptr
    */
    explicit RollSushi(QWidget* parent = nullptr);

    /**
     * @brief destructor for the rolling sushi window
    */
    ~RollSushi() {}

    /**
     * @brief generate a random string
     * @return a QString with random letters
     */
    QString generateRandString();

    /**
     * @brief generate a vector of random QStrings
    */
    void generateRandVec();

    /**
     * @brief get the user input
     * @return a QString
     */
    const QString getstr();

    /**
     * @brief key press event to start the game once pressing '0'
     * @param event - QKeyEvent*
    */
    void keyPressEvent(QKeyEvent* event);

    /**
     * @brief starts the timer for the game
    */
    void TimerStart();

    /**
     * @brief gets the score of the game
     * @return an int
     */
    int get_score() const;

    QPushButton* finish;

public slots:
    /**
     * @brief gest the updated string from the user input
    */
    void updateString();

    /**
     * @brief stop the timer for the game
    */
    void stopTimer();

    /**
     * @brief add pictures of the sushi making steps to a vector
    */
    void generateSteps();

private:
    QWidget* sushiWindow;
    QVector<QString> vec;
    QString string;
    QLineEdit* edit;
    QLabel* randomString;
    int vec_index = 0;
    QVBoxLayout* sushiLayout;
    QLabel* message;
    int score = 0;
    QTimer* timer;
    QLabel* instruction;
    QGridLayout* sushiSteps;
    QVector<QWidget*> steps;
    QWidget* images;
    int rows = 0;
    int columns = 0;
};



#endif // ROLLSUSHI_H
