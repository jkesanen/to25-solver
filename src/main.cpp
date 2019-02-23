#include <iostream>

#include "board.hpp"
#include "solver.hpp"
#include "types.hpp"

using namespace game;

static int depth = 0;

static int solutions = 0;
static int deadEnds = 0;

void trySolutions(Solver& solver, Board& state)
{
    Solver::direction_t direction = Solver::Directions::N;

    for (; direction <= Solver::Directions::NW; ++direction) {
        auto newDirection = solver.nextMove(state, direction);

        if (state.isSolved()) {
            solutions++;
            state.output();
            std::cout << "----------------" << std::endl;
            state.pop_back();
            break;
        }

        if (!newDirection.has_value()) {
            deadEnds++;
            break;
        }

        trySolutions(solver, state);

        // pop the previous
        state.pop_back();

        direction = newDirection.value();
    }
}

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;

    Solver solver;

    Board gamestate(5, 5);
    gamestate.insert(position_t(0, 0));

    trySolutions(solver, gamestate);

    std::cout << "----------------" << std::endl << "solutions: " << solutions << std::endl;
    std::cout << "dead ends: " << deadEnds << std::endl << "----------------" << std::endl;

    return 0;
}
