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
    ~MainWindow();
private:
    gui::grid *grid;
    QHBoxLayout *layout;
    QVBoxLayout *mainarea;
    QVBoxLayout *sidebar;
    QHBoxLayout *setIntervalLayout;
    QHBoxLayout *buttons;
    QPushButton *startbtn;
    QPushButton *pausebtn;
    QPushButton *clearbtn;
    QLineEdit *setInterval;
    QLabel *generation;
    QLabel *refreshLabel;
private slots:
    void handleStartButton();
    void handlePauseButton();
    void handleClearButton();
    void handleSetIntervalLineEdit();
    void updateGenerationLabel();
};

#endif // MAINWINDOW_H
