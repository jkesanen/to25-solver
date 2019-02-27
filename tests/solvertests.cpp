#include <set>

#include "gtest/gtest.h"
#include "board.hpp"
#include "solver.hpp"

using namespace to25;

TEST (SolverTest, NextPosition) {

    Board gameboard(5, 5);
    gameboard.insert(position_t{ 4, 4 });

    // In 5x5 board the possible moves from (4, 4) are:
    std::set<position_t> possibilities{ { 1, 4 }, { 4, 1 }, { 2, 2 } };

    Solver solver;
    Solver::direction_t direction = Solver::Directions::N;

    while (direction <= Solver::Directions::NW) {
        auto addedDirection = solver.nextPosition(gameboard, direction);

        // The added position should be in the set of possible moves.
        EXPECT_TRUE(possibilities.extract(gameboard.latest().value()));

        // Remove the position to try the next one.
        gameboard.pop_back();

        // Try the next possible direction.
        direction = addedDirection.value();
        ++direction;
    }

    // All the possible positions have been tried and the list of possible moves is empty.
    ASSERT_EQ(0u, possibilities.size());
}
