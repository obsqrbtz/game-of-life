#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include "grid_qt.h"

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
private:
    gui::grid *grid;
    QPushButton *startbtn;
    QPushButton *pausebtn;
private slots:
    void handleStartButton();
    void handlePauseButton();
};

#endif // MAINWINDOW_H
