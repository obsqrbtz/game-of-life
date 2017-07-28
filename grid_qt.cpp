#include "grid_qt.h"

namespace gui{
    grid::grid(int cellSizeNew, int widthNew, int heightNew)
    {
        QGraphicsScene *scene = new QGraphicsScene;
        int i, j;
        cellSize = cellSizeNew;
        width = widthNew;
        height = heightNew;
        iMax = width / cellSize - 1;
        jMax = height / cellSize - 1;
        cell = new Cell **[iMax + 1];
        for (i = 0; i <= iMax; i++) cell[i] = new Cell *[jMax + 1];
        i = 0;
        j = 0;
        for (int y = 0; y <= height - cellSize; y+=cellSize){
            for(int x = 0; x <= width - cellSize; x+=cellSize){
                cell[i][j] = new Cell(x,y,cellSize);
                if (i == 0 || i == iMax || j == jMax || j == 0) cell[i][j]->border = true;
                scene->addItem(cell[i][j]);
                j++;
            }
            i++;
            j = 0;
        }
        setScene(scene);
        setSceneRect(0, 0, width, height);
        setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
        timerActive = false;
        timerInterval = 100;
        generation = 1;
        gGrid = new game::grid(iMax, jMax);
    }
    grid::~grid(){
        for(int i = 0; i <= iMax; i++) delete[] cell[i];
        delete[] cell;
        delete gGrid;
    }

    void grid::timerEvent(QTimerEvent *){
        game::grid state(iMax, jMax);
        for(int i = 1; i < iMax; i++){
            for(int j = 1; j < jMax; j++) gGrid->setStatus(i,j,cell[i][j]->alive);
        }
        state = gGrid->calculateNewState(*gGrid);
        generation++;
        emit generationChanged();
        for (int i = 1; i < iMax; i++){
            for(int j = 1; j < jMax; j++){
                cell[i][j]->alive = state.getCell(i,j);
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
        for(int i = 0; i < iMax; i++){
            for(int j = 0; j < jMax; j++){
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
    void grid::writeStateToFile(QString filename){
        for(int i = 1; i < iMax; i++){
            for(int j = 1; j < jMax; j++) gGrid->setStatus(i,j,cell[i][j]->alive);
        }
        gGrid->writeStateToFile(filename.toStdString());
    }
    void grid::readStateFromFile(QString filename){
        clear();
        gGrid->readStateFromFile(filename.toStdString());
        for(int i = 1; i < iMax; i++){
            for(int j = 1; j < jMax; j++){
                cell[i][j]->alive = gGrid->getCell(i,j);
                cell[i][j]->update();
            }
        }
    }

    QString grid::gridGeneration(){
        return QString::number(generation);
    }
}
