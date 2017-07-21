#ifndef GRID_H
#define GRID_H
#include <vector>

namespace game {
    class grid
    {
    private:
        std::vector<std::vector<bool>> cell;
        int iMax;
        int jMax;
    public:
        grid(int iNew, int jNew);
        grid calculateNewState(grid tGrid);
        bool getCell(int i, int j);
        void setStatus(int i, int j, bool status);
    };
}
#endif // GRID_H
