#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFont>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *central = new QWidget;
    setCentralWidget(central);

    player1Bar = new QProgressBar;
    player2Bar = new QProgressBar;

    player1Bar->setRange(0,100);
    player2Bar->setRange(0,100);

    player1Button = new QPushButton("Switch player");
    player2Button = new QPushButton("Switch player");

    time120Button = new QPushButton("120 sec");
    time5minButton = new QPushButton("5 min");

    startButton = new QPushButton("START GAME");
    stopButton = new QPushButton("STOP GAME");

    infoLabel = new QLabel("Select playtime and press start game!");
    infoLabel->setAlignment(Qt::AlignCenter);

    timer = new QTimer(this);

    gameTime = 0;
    player1Time = 0;
    player2Time = 0;

    player1Turn = true;

    connect(timer,SIGNAL(timeout()),this,SLOT(timeout()));

    connect(startButton,SIGNAL(clicked()),this,SLOT(startGame()));
    connect(stopButton,SIGNAL(clicked()),this,SLOT(stopGame()));

    connect(player1Button,SIGNAL(clicked()),this,SLOT(player1Switch()));
    connect(player2Button,SIGNAL(clicked()),this,SLOT(player2Switch()));

    connect(time120Button,SIGNAL(clicked()),this,SLOT(set120sec()));
    connect(time5minButton,SIGNAL(clicked()),this,SLOT(set5min()));

    QHBoxLayout *topLayout = new QHBoxLayout;
    topLayout->addWidget(player1Bar);
    topLayout->addWidget(player2Bar);

    QHBoxLayout *switchLayout = new QHBoxLayout;
    switchLayout->addWidget(player1Button);
    switchLayout->addWidget(player2Button);

    QHBoxLayout *timeLayout = new QHBoxLayout;
    timeLayout->addWidget(time120Button);
    timeLayout->addWidget(time5minButton);

    QHBoxLayout *controlLayout = new QHBoxLayout;
    controlLayout->addWidget(startButton);
    controlLayout->addWidget(stopButton);

    QVBoxLayout *mainLayout = new QVBoxLayout;

    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(switchLayout);
    mainLayout->addWidget(infoLabel);
    mainLayout->addLayout(timeLayout);
    mainLayout->addLayout(controlLayout);

    central->setLayout(mainLayout);

    resize(400,250);
}

void MainWindow::set120sec()
{
    gameTime = 120;

    player1Time = gameTime;
    player2Time = gameTime;

    updateProgressBar();

    setGameInfoText("Ready to play",12);
}

void MainWindow::set5min()
{
    gameTime = 300;

    player1Time = gameTime;
    player2Time = gameTime;

    updateProgressBar();

    setGameInfoText("Ready to play",12);
}

void MainWindow::startGame()
{
    if(gameTime == 0)
        return;

    player1Turn = true;

    timer->start(1000);

    setGameInfoText("Game ongoing",14);
}

void MainWindow::stopGame()
{
    timer->stop();

    player1Time = 0;
    player2Time = 0;

    updateProgressBar();

    setGameInfoText("New game via start button",12);
}

void MainWindow::player1Switch()
{
    player1Turn = false;
}

void MainWindow::player2Switch()
{
    player1Turn = true;
}

void MainWindow::timeout()
{
    if(player1Turn)
        player1Time--;
    else
        player2Time--;

    updateProgressBar();

    if(player1Time <= 0)
    {
        timer->stop();
        setGameInfoText("Player 2 WON!!",16);
    }

    if(player2Time <= 0)
    {
        timer->stop();
        setGameInfoText("Player 1 WON!!",16);
    }
}

void MainWindow::updateProgressBar()
{
    if(gameTime == 0)
        return;

    int p1 = (player1Time*100)/gameTime;
    int p2 = (player2Time*100)/gameTime;

    player1Bar->setValue(p1);
    player2Bar->setValue(p2);
}

void MainWindow::setGameInfoText(QString text, short size)
{
    infoLabel->setText(text);

    QFont f = infoLabel->font();
    f.setPointSize(size);
    infoLabel->setFont(f);
}
