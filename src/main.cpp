#include <iostream>

#include "board.hpp"
#include "solver.hpp"
#include "types.hpp"

using namespace game;

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;

    Solver solver;

    auto dir = Solver::Directions::N;
    Board gamestate(5, 5);
    gamestate.insert(position_t(0, 0));

    while (true) {
        auto direction = solver.nextMove(gamestate, dir);

        if (!direction.has_value()) {
            break;
        }

        dir = Solver::Directions::N;
    }

    gamestate.output();

    std::cout << " -----------------" << std::endl;

    while (gamestate.latest().has_value()) {
        gamestate.pop_back();
        gamestate.output();
        std::cout << " -----------------" << std::endl;
    }

    return 0;
}
