#include "grid.h"

namespace game {
    grid grid::calculateNewState(grid tGrid){
        grid nGrid = tGrid;
        for (int i = 1; i < 99; i++){
            for(int j = 1; j < 99; j++){
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
}
