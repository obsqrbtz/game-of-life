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
    public:
        grid();
        void start();
        void pause();
    protected:
        void timerEvent(QTimerEvent*);
    private:
        Cell *cell[50][50];
        game::grid gGrid;
        int timerID;
        bool timerActive;
    };
}
#endif // GRID_QT_H
