#include <set>
#include <vector>

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

TEST(SolverTest, NoNextPosition)
{
    // Add positions of a dead end game.
    /*  ******************
        *  1    12  2  7 *
        *   <18> 5    10 *
        * 15     8 16 13 *
        *  4    11  3  6 *
        *    17 14     9 *
        ******************/
    const std::vector<position_t> game{
        position_t{ 0, 0 }, position_t{ 0, 3 }, position_t{ 3, 3 }, position_t{ 3, 0 },
        position_t{ 1, 2 }, position_t{ 3, 4 }, position_t{ 0, 4 }, position_t{ 2, 2 },
        position_t{ 4, 4 }, position_t{ 1, 4 }, position_t{ 3, 2 }, position_t{ 0, 2 },
        position_t{ 2, 4 }, position_t{ 4, 2 }, position_t{ 2, 0 }, position_t{ 2, 3 },
        position_t{ 4, 1 }, position_t{ 1, 1 } };

    // Populate the board.
    Board gameboard(5, 5);
    for (auto position : game) {
        ASSERT_TRUE(gameboard.insert(position));
    }

    Solver solver;
    Solver::direction_t direction{ Solver::Directions::N };

    // No possible moves left.
    ASSERT_FALSE(solver.nextPosition(gameboard, direction));
}

TEST(SolverTest, SolveSolvable)
{
    // Add positions of a solvable game.
    /*  ******************
        *  1     7  4    *
        *  9    15 12    *
        * 17  5    18  6 *
        *  2 13  8  3 14 *
        * 10 19 16 11    *
        ******************/
    std::vector<position_t> game{
        position_t{ 0, 0 }, position_t{ 3, 0 }, position_t{ 3, 3 }, position_t{ 0, 3 },
        position_t{ 2, 1 }, position_t{ 2, 4 }, position_t{ 0, 2 }, position_t{ 3, 2 },
        position_t{ 1, 0 }, position_t{ 4, 0 }, position_t{ 4, 3 }, position_t{ 1, 3 },
        position_t{ 3, 1 }, position_t{ 3, 4 }, position_t{ 1, 2 }, position_t{ 4, 2 },
        position_t{ 2, 0 }, position_t{ 2, 3 }, position_t{ 4, 1 }
    };

    Board gameboard(5, 5);

    // Populate the board.
    for (auto position : game) {
        ASSERT_TRUE(gameboard.insert(position));
    }

    class Results : public to25::ResultBase {

    public:
        void addSolved([[maybe_unused]] const to25::Board& board) override { ++mNumSolved; };
        void addDeadEnd([[maybe_unused]] const to25::Board& board) override {};
        uint32_t solved() const { return mNumSolved; };

    private:
        uint32_t mNumSolved{0};
    };

    {
        Results results;

        Solver solver;
        solver.solve(gameboard, results);

        ASSERT_EQ(1u, results.solved());
    }

    // Remove the last position (19th) and the game will have 3 possible solutions.
    gameboard.pop_back();

    {
        Results results;

        Solver solver;
        solver.solve(gameboard, results);

        ASSERT_EQ(3u, results.solved());
    }
}
