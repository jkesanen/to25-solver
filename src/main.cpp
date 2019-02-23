#include <iostream>

#include "board.hpp"
#include "solver.hpp"
#include "types.hpp"

using namespace game;

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;

    // Put the starting position into the upper left corner.
    Board gameboard(5, 5);
    gameboard.insert(position_t(0, 0));

    // Start solver
    Solver solver;
    solver.solve(gameboard);

    return 0;
}
