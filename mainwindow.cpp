#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout;
    QHBoxLayout *buttons = new QHBoxLayout;
    grid = new gui::grid;
    startbtn = new QPushButton;
    startbtn->setText("Start");
    pausebtn = new QPushButton;
    pausebtn->setText("Pause");
    clearbtn = new QPushButton;
    clearbtn->setText("Clear");
    connect(startbtn, SIGNAL(clicked()), this, SLOT(handleStartButton()));
    connect(pausebtn, SIGNAL(clicked()), this, SLOT(handlePauseButton()));
    connect(clearbtn, SIGNAL(clicked()), this, SLOT(handleClearButton()));
    buttons->addWidget(startbtn);
    buttons->addWidget(pausebtn);
    buttons->addWidget(clearbtn);
    layout->addWidget(grid);
    layout->addLayout(buttons);
    setLayout(layout);
}
void MainWindow::handleStartButton(){
    grid->start();
}
void MainWindow::handlePauseButton(){
    grid->pause();
}
void MainWindow::handleClearButton(){
    grid->clear();
}
