#include "mainwindow.h"

/*
 * Save & Open buttons are not working yet.
 */
MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    layout = new QHBoxLayout;
    mainarea = new QVBoxLayout;
    sidebar = new QVBoxLayout;
    setIntervalLayout = new QHBoxLayout;
    buttons = new QHBoxLayout;
    files = new QHBoxLayout;
    refreshLabel = new QLabel;
    grid = new gui::grid(5,400,400);
    startbtn = new QPushButton;
    startbtn->setText("Start");
    pausebtn = new QPushButton;
    pausebtn->setText("Pause");
    clearbtn = new QPushButton;
    clearbtn->setText("Clear");
    savebtn = new QPushButton;
    savebtn->setText("Save");
    openbtn = new QPushButton;
    openbtn->setText("Open");
    setInterval = new QLineEdit;
    setInterval->setText("100");
    pausebtn->setEnabled(false);
    clearbtn->setEnabled(false);
    generation = new QLabel;
    refreshLabel->setText("Refresh interval: ");
    connect(startbtn, SIGNAL(clicked()), this, SLOT(handleStartButton()));
    connect(pausebtn, SIGNAL(clicked()), this, SLOT(handlePauseButton()));
    connect(clearbtn, SIGNAL(clicked()), this, SLOT(handleClearButton()));
    connect(savebtn, SIGNAL(clicked()), this, SLOT(handleSaveButton()));
    connect(openbtn, SIGNAL(clicked()), this, SLOT(handleOpenButton()));
    connect(setInterval, SIGNAL(textEdited(const QString &)), this, SLOT(handleSetIntervalLineEdit()));
    connect(grid, SIGNAL(generationChanged()), this, SLOT(updateGenerationLabel()));
    buttons->addWidget(startbtn);
    buttons->addWidget(pausebtn);
    buttons->addWidget(clearbtn);
    files->addWidget(savebtn);
    files->addWidget(openbtn);
    mainarea->addWidget(grid);
    setIntervalLayout->addWidget(refreshLabel);
    setIntervalLayout->addWidget(setInterval);
    sidebar->addWidget(generation);
    generation->setText("Generation: 1");
    sidebar->addLayout(setIntervalLayout);
    sidebar->addLayout(buttons);
    sidebar->addLayout(files);
    sidebar->setAlignment(Qt::AlignTop);
    layout->addLayout(mainarea);
    layout->addLayout(sidebar);
    setLayout(layout);
    setWindowTitle("Conway's Game of Life");
}
MainWindow::~MainWindow(){
    delete startbtn;
    delete pausebtn;
    delete clearbtn;
    delete setInterval;
    delete generation;
    delete refreshLabel;
    delete buttons;
    delete setIntervalLayout;
    delete sidebar;
    delete mainarea;
    delete layout;
    delete grid;
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
void MainWindow::handleSaveButton(){
    QString filename = QFileDialog::getSaveFileName(this, tr("Save state"));
    if(filename.isEmpty()){
        return;
    }else{
        QFile statefile(filename);
        if(!statefile.open(QIODevice::WriteOnly)){
            QMessageBox::information(this, tr("Unable to open file"), statefile.errorString());
            return;
        }
        grid->writeStateToFile(filename);
    }
}
void MainWindow::handleOpenButton(){
    QString filename = QFileDialog::getOpenFileName(this, tr("Open state"));
    if(filename.isEmpty()){
        return;
    }else{
        QFile statefile(filename);
        if(!statefile.open(QIODevice::ReadOnly)){
            QMessageBox::information(this, tr("Unable to open file"), statefile.errorString());
            return;
        }
    }
}
void MainWindow::handleSetIntervalLineEdit(){
    grid->setInterval(setInterval->text().toInt());
}
void MainWindow::updateGenerationLabel(){
    generation->setText("Generation: "+grid->gridGeneration());
    generation->update();
}
