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
    QPushButton *clearbtn;
private slots:
    void handleStartButton();
    void handlePauseButton();
    void handleClearButton();
};

#endif // MAINWINDOW_H
