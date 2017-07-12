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
    connect(startbtn, SIGNAL(clicked()), this, SLOT(handleStartButton()));
    connect(pausebtn, SIGNAL(clicked()), this, SLOT(handlePauseButton()));
    buttons->addWidget(startbtn);
    buttons->addWidget(pausebtn);
    layout->addWidget(grid);
    layout->addLayout(buttons);
    //layout->addWidget(startbtn);
    setLayout(layout);
}
void MainWindow::handleStartButton(){
    grid->start();
}
void MainWindow::handlePauseButton(){
    grid->pause();
}
