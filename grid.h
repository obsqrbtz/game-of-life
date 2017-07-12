#ifndef GRID_H
#define GRID_H

namespace game {
    class grid
    {
    public:
         bool cell[50][50];
         grid calculateNewState(grid tGrid);
    };
}
#endif // GRID_H
