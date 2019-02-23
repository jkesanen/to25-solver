#include <iostream>

#include "board.hpp"
#include "solver.hpp"

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;

    // Put the starting position into the upper left corner.
    to25::Board gameboard(5, 5);
    gameboard.insert(to25::position_t(0, 0));

    // Start solver
    to25::Solver solver;
    solver.solve(gameboard);

    return 0;
}
