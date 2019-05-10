#include "grid.h"

namespace game {
    grid::grid(int iNew, int jNew){
        cell.resize(iNew + 1);
        for(int i = 0; i <=  iNew; i++) cell[i].resize(jNew + 1);
        for (int i = 0; i <= iNew; i++){
            for (int j = 0; j <= jNew; j++) cell[i][j] = false;
        }
        iMax = iNew;
        jMax = jNew;
    }
    bool grid::getCell(int i, int j){
        return cell[i][j];
    }
    void grid::setStatus(int i, int j, bool status){
        cell[i][j] = status;
    }
//  for(int in = (i + iMax) % (iMax + 1); in <= (i + 1) % (iMax + 1); in++){
//  if(tGrid.cell[in][jn] && (in != i || jn != j)) neighbors++;
    int grid::countNeighbors(int i, int j, grid tGrid){
        int H = iMax + 1, V = jMax +1;
        return (int)tGrid.cell[(i-1+H)%H][(j-1+V)%V] +
            (int)tGrid.cell[(i-1+H)%H][(j+1)%V] +
            (int)tGrid.cell[(i+1)%H][(j-1+V)%V] +
            (int)tGrid.cell[(i+1)%H][(j+1)%V] +
            (int)tGrid.cell[i][(j-1+V)%V] +
            (int) tGrid.cell[i][(j+1)%V] +
            (int)tGrid.cell[(i-1+H)%H][j] +
            (int)tGrid.cell[(i+1)%H][j];
    }
    grid grid::calculateNewState(grid tGrid){
       grid nGrid = tGrid;
       for (int i = 0; i <= iMax; i++){
            for(int j = 0; j <= jMax; j++){
                //int neighbors = countNeighbors(i, j, tGrid);
                int H = iMax + 1, V = jMax + 1,
                    neighbors = (int)tGrid.cell[(i-1+H)%H][(j-1+V)%V] +
                        (int)tGrid.cell[(i-1+H)%H][(j+1)%V] +
                        (int)tGrid.cell[(i+1)%H][(j-1+V)%V] +
                        (int)tGrid.cell[(i+1)%H][(j+1)%V] +
                        (int)tGrid.cell[i][(j-1+V)%V] +
                        (int) tGrid.cell[i][(j+1)%V] +
                        (int)tGrid.cell[(i-1+H)%H][j] +
                        (int)tGrid.cell[(i+1)%H][j];
                if (tGrid.cell[i][j] && (neighbors < 2 || neighbors > 3)){
                    nGrid.cell[i][j] = false;
                }
                if (!tGrid.cell[i][j] && neighbors == 3) nGrid.cell[i][j] = true;
            }
        }

    return nGrid;
    }
    void grid::writeStateToFile(std::string filename){
        std::ofstream output(filename);
        for(int i = 0; i <= iMax; i++){
            for(int j = 0; j <= jMax; j++) output << cell[i][j];
            output << std::endl;
        }
        output.close();
    }
    void grid::readStateFromFile(std::string filename){
        std::ifstream input(filename);
        char temp;
        for(int i = 0; i <= iMax; i++){
            for(int j = 0; j <= jMax; j++){
                input >> temp;
                if(temp == '0' || i == 0 || i == iMax || j == 0 || j == jMax) cell[i][j] = false;
                if(temp == '1' && i != 0 && i != iMax && j != 0 && j != jMax) cell[i][j] = true;
            }
        }
        input.close();
    }
}
