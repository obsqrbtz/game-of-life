#include "grid_qt.h"
namespace gui{
    grid::grid()
    {
        QGraphicsScene *scene = new QGraphicsScene;
        int i = 0, j = 0;
        for (int y = 0; y <= 396; y+=4){
            for(int x = 0; x <= 396; x+=4){
                cell[i][j] = new Cell;
                if (i == 0 || i == 99 || j == 99 || j == 0) cell[i][j]->border = true;
                cell[i][j]->setCoordinates(x,y);
                scene->addItem(cell[i][j]);
                i++;
            }
            j++;
            i = 0;
        }
        setScene(scene);
        setSceneRect(0,0,400,400);
        setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
        timerActive = false;
        timerInterval = 100;
        generation = 1;
    }
    void grid::timerEvent(QTimerEvent *){
        for(int i = 1; i < 99; i++){
            for(int j = 1; j < 99; j++){
                gGrid.cell[i][j] = cell[i][j]->alive;
            }
        }
        game::grid state = gGrid.calculateNewState(gGrid);
        generation++;
        emit generationChanged();
        for (int i = 1; i < 99; i++){
            for(int j = 1; j < 99; j++){
                cell[i][j]->alive = state.cell[i][j];
                if(cell[i][j]->alive && !cell[i][j]->wereAlive) cell[i][j]->wereAlive = true;
                cell[i][j]->update();
            }
        }
        update();
    }
    void grid::start(){
        if(!timerActive){
            if(isEnabled()) setEnabled(false);
            timerID = startTimer(timerInterval);
            timerActive = true;
        }
    }
    void grid::pause(){
        killTimer(timerID);
        if(!isEnabled()) setEnabled(true);
        timerActive = false;
    }
    void grid::clear(){
        for(int i = 0; i < 99; i++){
            for(int j = 0; j < 99; j++){
                generation = 1;
                emit generationChanged();
                pause();
                cell[i][j]->alive = false;
                cell[i][j]->wereAlive = false;
                cell[i][j]->update();
            }
        }
    }
    void grid::setInterval(int interval){
        timerInterval = interval;
    }
    QString grid::gridGeneration(){
        return QString::number(generation);
    }
}
