#include <cassert>

#include "solver.hpp"

namespace to25 {

const std::array<position_t, 8> Solver::sPositionUpdates{
    position_t{ -3, 0 }, // N
    position_t{ -2, 2 }, // NE
    position_t{ 0, 3 },  // E
    position_t{ 2, 2 },  // SE
    position_t{ 3, 0 },  // S
    position_t{ 2, -2 }, // SW
    position_t{ 0, -3 }, // W
    position_t{ -2, -2 } // NW
};

bool Solver::isAllowedPosition(Board& board, position_t pos) const
{
    const pos_coord_t boardWidth = static_cast<pos_coord_t>(board.width());
    const pos_coord_t boardHeight = static_cast<pos_coord_t>(board.height());

    return ((pos.first >= 0) &&
        (pos.first < boardWidth) &&
        (pos.second >= 0) &&
        (pos.second < boardHeight));
}

std::optional<Solver::direction_t> Solver::nextPosition(Board& board, direction_t startDirection) const
{
    assert(board.latest().has_value());
    assert(startDirection <= NW);

    if (!board.latest().has_value()) {
        // The board has to have at least one position.
        return std::nullopt;
    }

    for (direction_t dir = startDirection; dir < sPositionUpdates.size(); ++dir) {
        position_t newPosition = board.latest().value();

        newPosition.first += sPositionUpdates[dir].first;
        newPosition.second += sPositionUpdates[dir].second;

        if (isAllowedPosition(board, newPosition)) {
            if (board.insert(newPosition)) {
                // Returns the direction from previous position to the just added position.  
                return dir;
            }
        }
    }

    // No available moves from the latest position.
    return std::nullopt;
}

void Solver::solve(Board& board, ResultBase& results) const
{
    Solver::direction_t direction = Solver::Directions::N;

    for (; direction <= Solver::Directions::NW; ++direction) {
        auto addedDirection = nextPosition(board, direction);

        if (board.isSolved()) {
            results.addSolved(board);
            // Pop the just added board solving position.
            board.pop_back();
            break;
        }

        if (!addedDirection.has_value()) {
            // Dead end: the board is not solved and no allowed positions left.
            results.addDeadEnd(board);
            break;
        }

        // Recursively call this function to test the further positions.
        solve(board, results);

        // Pop the previous position.
        board.pop_back();

        direction = addedDirection.value();
    }
}

}; // namespace to25
