#include "grid.h"

namespace game {
    grid::grid(int iNew, int jNew){
        cell.resize(iNew + 1);
        for(int i = 0; i <= iNew; i++) cell[i].resize(jNew + 1);
        iMax = iNew;
        jMax = jNew;
    }
    bool grid::getCell(int i, int j){
        return cell[i][j];
    }
    void grid::setStatus(int i, int j, bool status){
        cell[i][j] = status;
    }

    grid grid::calculateNewState(grid tGrid){
        grid nGrid = tGrid;
        for (int i = 1; i < iMax; i++){
            for(int j = 1; j < jMax; j++){
                int neighbors = 0;
                for(int in = i - 1; in <= i + 1; in++){
                    for(int jn = j - 1; jn <= j + 1; jn++){
                        if(tGrid.cell[in][jn] && (in != i || jn != j)) neighbors++;
                    }
                }
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
                if(temp == '0') cell[i][j] = false;
                if(temp == '1') cell[i][j] = true;
            }
        }
        input.close();
    }
}
