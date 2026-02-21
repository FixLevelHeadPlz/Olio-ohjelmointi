#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , counter(0)
{
    ui->setupUi(this);

    // yhdistetään napit funktioihin
    connect(ui->countButton, &QPushButton::clicked, this, &MainWindow::countClicked);
    connect(ui->resetButton, &QPushButton::clicked, this, &MainWindow::resetClicked);

    ui->lineEdit->setText(QString::number(counter)); // näytetään aluksi 0
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::countClicked()
{
    counter++;
    ui->lineEdit->setText(QString::number(counter));
}

void MainWindow::resetClicked()
{
    counter = 0;
    ui->lineEdit->setText(QString::number(counter));
}
