#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout *layout = new QHBoxLayout;
    QVBoxLayout *mainarea = new QVBoxLayout;
    QVBoxLayout *sidebar = new QVBoxLayout;
    QHBoxLayout *setIntervalLayout = new QHBoxLayout;
    QHBoxLayout *buttons = new QHBoxLayout;
    QLabel *refreshLabel = new QLabel;
    grid = new gui::grid(4,400,400);
    startbtn = new QPushButton;
    startbtn->setText("Start");
    pausebtn = new QPushButton;
    pausebtn->setText("Pause");
    clearbtn = new QPushButton;
    clearbtn->setText("Clear");
    setInterval = new QLineEdit;
    setInterval->setText("100");
    pausebtn->setEnabled(false);
    clearbtn->setEnabled(false);
    generation = new QLabel;
    refreshLabel->setText("Refresh interval: ");
    connect(startbtn, SIGNAL(clicked()), this, SLOT(handleStartButton()));
    connect(pausebtn, SIGNAL(clicked()), this, SLOT(handlePauseButton()));
    connect(clearbtn, SIGNAL(clicked()), this, SLOT(handleClearButton()));
    connect(setInterval, SIGNAL(textEdited(const QString &)), this, SLOT(handleSetIntervalLineEdit()));
    connect(grid, SIGNAL(generationChanged()), this, SLOT(updateGenerationLabel()));
    buttons->addWidget(startbtn);
    buttons->addWidget(pausebtn);
    buttons->addWidget(clearbtn);
    mainarea->addWidget(grid);
    setIntervalLayout->addWidget(refreshLabel);
    setIntervalLayout->addWidget(setInterval);
    sidebar->addLayout(setIntervalLayout);
    sidebar->addLayout(buttons);
    sidebar->addWidget(generation);
    generation->setText("Generation: 1");
    sidebar->setAlignment(Qt::AlignTop);
    layout->addLayout(mainarea);
    layout->addLayout(sidebar);
    setLayout(layout);
    setWindowTitle("Conway's Game of Life");
}
void MainWindow::handleStartButton(){
    grid->start();
    setInterval->setEnabled(false);
    startbtn->setEnabled(false);
    if(!clearbtn->isEnabled()) clearbtn->setEnabled(true);
    if(!pausebtn->isEnabled()) pausebtn->setEnabled(true);
}
void MainWindow::handlePauseButton(){
    grid->pause();
    setInterval->setEnabled(true);
    startbtn->setEnabled(true);
    pausebtn->setEnabled(false);
    if(!clearbtn->isEnabled()) clearbtn->setEnabled(true);
}
void MainWindow::handleClearButton(){
    grid->clear();
    if(!setInterval->isEnabled()) setInterval->setEnabled(true);
    if(!startbtn->isEnabled()) startbtn->setEnabled(true);
    if(pausebtn->isEnabled()) pausebtn->setEnabled(false);
}
void MainWindow::handleSetIntervalLineEdit(){
    grid->setInterval(setInterval->text().toInt());
}
void MainWindow::updateGenerationLabel(){
    generation->setText("Generation: "+grid->gridGeneration());
    generation->update();
}
