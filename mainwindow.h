#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
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
    QLineEdit *setInterval;
    QLabel *generation;
private slots:
    void handleStartButton();
    void handlePauseButton();
    void handleClearButton();
    void handleSetIntervalLineEdit();
    void updateGenerationLabel();
};

#endif // MAINWINDOW_H
