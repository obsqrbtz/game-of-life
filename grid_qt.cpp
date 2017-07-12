#include "grid_qt.h"
namespace gui{
    grid::grid()
    {
        QGraphicsScene *scene = new QGraphicsScene;
        int i = 0, j = 0;
        for (int y = 0; y <= 490; y+=10){
            for(int x = 0; x <= 490; x+=10){
                cell[i][j] = new Cell;
                cell[i][j]->setCoordinates(x,y);
                scene->addItem(cell[i][j]);
                i++;
            }
            j++;
            i = 0;
        }
        setScene(scene);
        setSceneRect(0,0,500,500);
        setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
        timerActive = false;
    }
    void grid::timerEvent(QTimerEvent *){
        for(int i = 0; i < 50; i++){
            for(int j = 0; j < 50; j++){
                gGrid.cell[i][j] = cell[i][j]->alive;
            }
        }
        game::grid state = gGrid.calculateNewState(gGrid);
        for (int i = 0; i < 50; i++){
            for(int j = 0; j < 50; j++){
                cell[i][j]->alive = state.cell[i][j];
                cell[i][j]->update();
            }
        }
        update();
    }
    void grid::start(){
        if(!timerActive){
            timerID = startTimer(5);
            timerActive = true;
        }
    }
    void grid::pause(){
        killTimer(timerID);
        timerActive = false;
    }
}
