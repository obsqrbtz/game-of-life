#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout;
    grid = new gui::grid;
    startbtn = new QPushButton;
    startbtn->setText("Start");
    connect(startbtn, SIGNAL(clicked()), this, SLOT(handleButton()));
    layout->addWidget(grid);
    layout->addWidget(startbtn);
    setLayout(layout);
}
void MainWindow::handleButton(){
    grid->start();
}
