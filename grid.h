#ifndef GRID_H
#define GRID_H

namespace game {
    class grid
    {
    public:
         bool cell[100][100];
         grid calculateNewState(grid tGrid);
    };
}
#endif // GRID_H
