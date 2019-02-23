#pragma once
#ifndef SOLVER_HPP
#define SOLVER_HPP

#include <array>
#include <optional>

#include "board.hpp"
#include "resultbase.hpp"
#include "types.hpp"

namespace to25 {

class Solver {

public:
    using direction_t = uint8_t;

    enum Directions : direction_t {
        N,
        NE,
        E,
        SE,
        S,
        SW,
        W,
        NW
    };

    bool isAllowedPosition(Board& board, position_t pos) const;

    std::optional<direction_t> nextPosition(Board& board, direction_t startDirection) const;

    void solve(Board& board, ResultBase& results) const;

private:
    static const std::array<position_t, 8> sPositionUpdates;
};

} // namespace to25
#endif
