#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , currentInput("")
    , pendingOp("")
{
    ui->setupUi(this);

    // Yhdistä numeronäppäimet samaan funktioon
    QList<QPushButton*> numButtons = {ui->N0,ui->N1,ui->N2,ui->N3,ui->N4,
                                       ui->N5,ui->N6,ui->N7,ui->N8,ui->N9};

    for(auto b : numButtons)
        connect(b, &QPushButton::clicked, this, &MainWindow::numberClicked);

    // Operaatiot
    connect(ui->add, &QPushButton::clicked, this, &MainWindow::operationClicked);
    connect(ui->sub, &QPushButton::clicked, this, &MainWindow::operationClicked);
    connect(ui->mul, &QPushButton::clicked, this, &MainWindow::operationClicked);
    connect(ui->div, &QPushButton::clicked, this, &MainWindow::operationClicked);

    // Enter ja Clear
    connect(ui->enter, &QPushButton::clicked, this, &MainWindow::enterClicked);
    connect(ui->clear, &QPushButton::clicked, this, &MainWindow::clearClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberClicked()
{
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    if(!btn) return;
    currentInput += btn->text();
    ui->num1->setText(currentInput);  // näyttää syötteen ensimmäisessä kentässä
}

void MainWindow::operationClicked()
{
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    if(!btn) return;

    ui->num2->setText(currentInput);  // tallennetaan ensimmäinen numero
    currentInput = "";                 // tyhjennetään seuraavaa syötettä varten
    pendingOp = btn->text();           // tallennetaan operaation tyyppi
}

void MainWindow::enterClicked()
{
    float n1 = ui->num2->text().toFloat();
    float n2 = currentInput.toFloat();
    float res = 0;

    if(pendingOp == "+") res = n1 + n2;
    else if(pendingOp == "-") res = n1 - n2;
    else if(pendingOp == "*") res = n1 * n2;
    else if(pendingOp == "/") res = n2 != 0 ? n1 / n2 : 0;

    ui->result->setText(QString::number(res));
    currentInput = QString::number(res);  // tulos seuraavaan syötteeseen
}

void MainWindow::clearClicked()
{
    ui->num1->setText("");
    ui->num2->setText("");
    ui->result->setText("");
    currentInput = "";
    pendingOp = "";
}
