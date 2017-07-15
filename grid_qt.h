#ifndef GRID_QT_H
#define GRID_QT_H

#include "cell.h"
#include "grid.h"
#include <QPainter>
#include <QGraphicsView>
#include <QVBoxLayout>

namespace gui{
    class grid : public QGraphicsView
    {
        Q_OBJECT
    public:
        grid();
        void start();
        void pause();
        void clear();
        void setInterval(int interval);
        QString gridGeneration();
    protected:
        void timerEvent(QTimerEvent*);
    private:
        Cell *cell[100][100];
        game::grid gGrid;
        int timerID;
        int timerInterval;
        int generation;
        bool timerActive;
    signals:
       generationChanged();
    };
}
#endif // GRID_QT_H
