#pragma once
#ifndef BOARD_HPP
#define BOARD_HPP

#include <array>
#include <optional>

#include "types.hpp"

namespace to25 {

class Board {

public:

    Board(const std::size_t width, const std::size_t height);

    bool insert(const position_t position);
    void pop_back();

    std::optional<position_t> latest() const;
    std::size_t width() const;
    std::size_t height() const;
    bool isSolved() const;

    void output() const;

private:
    std::size_t mWidth;
    std::size_t mHeight;

    /** NOTE: Using std::set + std::vector for convenience:
     *    - set for easy and efficient duplicate matching.
     *    - vector for ordering.
     */
    positions_t mPositions;
    order_t mOrder;
};

} // namespace to25

#endif
