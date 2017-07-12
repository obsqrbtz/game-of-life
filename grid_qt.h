#ifndef GRID_QT_H
#define GRID_QT_H

#include "cell.h"
#include <QPainter>
#include <QGraphicsView>
#include <QVBoxLayout>
namespace gui{
    class grid : public QGraphicsView
    {
    public:
        grid();
        void start();
    protected:
        void timerEvent(QTimerEvent*);
    private:
        Cell *cell[10][10];
    };
}
#endif // GRID_QT_H
