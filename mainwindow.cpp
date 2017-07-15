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
    setInterval->setText("100");
    pausebtn->setEnabled(false);
    clearbtn->setEnabled(false);
    generation = new QLabel;
    connect(startbtn, SIGNAL(clicked()), this, SLOT(handleStartButton()));
    connect(pausebtn, SIGNAL(clicked()), this, SLOT(handlePauseButton()));
    connect(clearbtn, SIGNAL(clicked()), this, SLOT(handleClearButton()));
    connect(setIntervalbtn, SIGNAL(clicked()), this, SLOT(handleSetIntervalButton()));
    connect(setInterval, SIGNAL(returnPressed()), this, SLOT(handleSetIntervalButton()));
    connect(grid, SIGNAL(generationChanged()), this, SLOT(updateGenerationLabel()));
    buttons->addWidget(startbtn);
    buttons->addWidget(pausebtn);
    buttons->addWidget(clearbtn);
    mainarea->addWidget(grid);
    setIntervalLayout->addWidget(setIntervalbtn);
    setIntervalLayout->addWidget(setInterval);
    sidebar->addLayout(setIntervalLayout);
    sidebar->addLayout(buttons);
    sidebar->addWidget(generation);
    generation->setText("Generation: 1");
    sidebar->setAlignment(Qt::AlignTop);
    layout->addLayout(mainarea);
    layout->addLayout(sidebar);
    setLayout(layout);
}
void MainWindow::handleStartButton(){
    grid->start();
    setIntervalbtn->setEnabled(false);
    setInterval->setEnabled(false);
    startbtn->setEnabled(false);
    if(!clearbtn->isEnabled()) clearbtn->setEnabled(true);
    if(!pausebtn->isEnabled()) pausebtn->setEnabled(true);
}
void MainWindow::handlePauseButton(){
    grid->pause();
    setIntervalbtn->setEnabled(true);
    setInterval->setEnabled(true);
    startbtn->setEnabled(true);
    pausebtn->setEnabled(false);
    if(!clearbtn->isEnabled()) clearbtn->setEnabled(true);
}
void MainWindow::handleClearButton(){
    grid->clear();
    if(!setIntervalbtn->isEnabled()) setIntervalbtn->setEnabled(true);
    if(!setInterval->isEnabled()) setInterval->setEnabled(true);
    if(!startbtn->isEnabled()) startbtn->setEnabled(true);
    if(pausebtn->isEnabled()) pausebtn->setEnabled(false);
}
void MainWindow::handleSetIntervalButton(){
    grid->setInterval(setInterval->text().toInt());
}
void MainWindow::updateGenerationLabel(){
    generation->setText("Generation: "+grid->gridGeneration());
    generation->update();
}
