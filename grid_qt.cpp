#include "grid_qt.h"
namespace gui{
    grid::grid()
    {
        QGraphicsScene *scene = new QGraphicsScene;
        int i = 0, j = 0;
        for (int y = 0; y <= 90; y+=10){
            for(int x = 0; x <= 90; x+=10){
                cell[i][j] = new Cell;
                cell[i][j]->setCoordinates(x,y);
                scene->addItem(cell[i][j]);
                i++;
            }
            j++;
            i = 0;
        }
        setScene(scene);
        setSceneRect(0,0,100,100);
        setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    }
    void grid::timerEvent(QTimerEvent *){
        int i = rand()%9;
        int j = rand()%9;
        cell[i][j]->alive = !cell[i][j]->alive;
        cell[i][j]->update();
        update();
    }
    void grid::start(){
        startTimer(1000);
    }
}
