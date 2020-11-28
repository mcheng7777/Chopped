#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLayout>
#include <QPushButton>
#include <QFontDatabase>
#include <QFont>
#include <QPixmap>
#include <QPalette>
#include <QPainter>
#include <QStackedWidget>
#include <QCheckBox>
#include <QGroupBox>
#include <QMediaPlayer>

namespace Ui {
class MainWindow;
}
/**
 * @brief The MainWindow class
 * @param parent - nullptr
 * welcome page to start game or quit application
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief constructor for the main window
    */
    explicit MainWindow(QWidget *parent = nullptr);

    /**
     * @brief destructor for the main window
    */
    ~MainWindow();


    /**
     * @brief Allows background to resize with window
       @param evt - pointer to a QResizeEvent object
     */
    void resizeEvent(QResizeEvent* evt);

    QPushButton* start;
    QPushButton* play;
    QPushButton* stop;
    QMediaPlayer* music;


public slots:

    /**
     * @brief plays the music
     */
    void playMusic();

    /**
     * @brief stops the music
     */
    void stopMusic();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
