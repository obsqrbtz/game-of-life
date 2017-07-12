#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout;
    gui::grid *grid = new gui::grid;
    grid->start();
    QPushButton *startbtn = new QPushButton;
    startbtn->setText("Start");
    layout->addWidget(grid);
    layout->addWidget(startbtn);
    setLayout(layout);
}
