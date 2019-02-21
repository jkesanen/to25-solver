#pragma once
#ifndef SOLVER_HPP
#define SOLVER_HPP

#include <array>
#include <optional>

#include "board.hpp"
#include "types.hpp"

using namespace game;

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


    bool isAllowedPosition(Board& s, position_t pos) const;

    std::optional<direction_t> nextMove(Board& s, direction_t startDirection) const;

private:
    static const std::array<position_t, 8> sPositionUpdates;
};

#endif
