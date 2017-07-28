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
        grid(int cellSizeNew, int widthNew, int heightNew);
        ~grid();
        void start();
        void pause();
        void clear();
        void setInterval(int interval);
        void writeStateToFile(QString filename);
        QString gridGeneration();
    protected:
        void timerEvent(QTimerEvent*);
    private:
        Cell ***cell;
        game::grid *gGrid;
        int timerID;
        int timerInterval;
        int generation;
        int cellSize;
        int width;
        int height;
        int iMax;
        int jMax;
        bool timerActive;
    signals:
       generationChanged();
    };
}
#endif // GRID_QT_H
