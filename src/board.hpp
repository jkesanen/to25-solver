#pragma once
#ifndef BOARD_HPP
#define BOARD_HPP

#include <array>
#include <optional>

#include "types.hpp"

using namespace game;

class Board {

public:

    Board(const int width, const int height);

    bool insert(const position_t position);

    void pop_back();

    std::optional<position_t> latest() const;

    void output() const;

    int width() const;
    int height() const;

private:
    int mWidth;
    int mHeight;

    positions_t mPositions;
    order_t mOrder;
};

#endif
