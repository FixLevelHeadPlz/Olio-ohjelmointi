#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProgressBar>
#include <QPushButton>
#include <QLabel>
#include <QTimer>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

public slots:
    void timeout();

private slots:
    void startGame();
    void stopGame();

    void player1Switch();
    void player2Switch();

    void set120sec();
    void set5min();

private:

    QProgressBar *player1Bar;
    QProgressBar *player2Bar;

    QPushButton *player1Button;
    QPushButton *player2Button;

    QPushButton *time120Button;
    QPushButton *time5minButton;

    QPushButton *startButton;
    QPushButton *stopButton;

    QLabel *infoLabel;

    QTimer *timer;

    int gameTime;
    int player1Time;
    int player2Time;

    bool player1Turn;

    void updateProgressBar();
    void setGameInfoText(QString text, short size);
};

#endif
