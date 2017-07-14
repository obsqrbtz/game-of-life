#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout *layout = new QHBoxLayout;
    QVBoxLayout *mainarea = new QVBoxLayout;
    QVBoxLayout *sidebar = new QVBoxLayout;
    QHBoxLayout *setIntervalLayout = new QHBoxLayout;
    QHBoxLayout *buttons = new QHBoxLayout;
    grid = new gui::grid;
    startbtn = new QPushButton;
    startbtn->setText("Start");
    pausebtn = new QPushButton;
    pausebtn->setText("Pause");
    clearbtn = new QPushButton;
    clearbtn->setText("Clear");
    setIntervalbtn = new QPushButton;
    setIntervalbtn->setText("Set interval");
    setInterval = new QLineEdit;
    connect(startbtn, SIGNAL(clicked()), this, SLOT(handleStartButton()));
    connect(pausebtn, SIGNAL(clicked()), this, SLOT(handlePauseButton()));
    connect(clearbtn, SIGNAL(clicked()), this, SLOT(handleClearButton()));
    buttons->addWidget(startbtn);
    buttons->addWidget(pausebtn);
    buttons->addWidget(clearbtn);
    mainarea->addWidget(grid);
    setIntervalLayout->addWidget(setIntervalbtn);
    setIntervalLayout->addWidget(setInterval);
    sidebar->addLayout(setIntervalLayout);
    sidebar->addLayout(buttons);
    layout->addLayout(mainarea);
    layout->addLayout(sidebar);
    setLayout(layout);
}
void MainWindow::handleStartButton(){
    grid->start(100);
}
void MainWindow::handlePauseButton(){
    grid->pause();
}
void MainWindow::handleClearButton(){
    grid->clear();
}
