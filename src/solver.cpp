#include <cassert>

#include "solver.hpp"

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

bool Solver::isAllowedPosition(Board& s, position_t pos) const
{
    return ((pos.first >= 0) &&
        (pos.first < s.width()) &&
        (pos.second >= 0) &&
        (pos.second < s.height()));
}

std::optional<Solver::direction_t> Solver::nextMove(Board& s, direction_t startDirection) const
{
    assert(s.latest().has_value());

    if (!s.latest().has_value()) {
        return std::nullopt;
    }

    for (direction_t dir = startDirection; dir < sPositionUpdates.size(); ++dir) {
        position_t newPosition = s.latest().value();

        newPosition.first += sPositionUpdates[dir].first;
        newPosition.second += sPositionUpdates[dir].second;

        if (isAllowedPosition(s, newPosition)) {
            if (s.insert(newPosition)) {
                return dir;
            }
        }
    }

    return std::nullopt;
}
