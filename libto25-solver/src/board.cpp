#include <cassert>
#include <iomanip>
#include <iostream>

#include "board.hpp"

namespace to25 {

Board::Board(const std::size_t width, const std::size_t height) :
    mWidth(width),
    mHeight(height)
{}

bool Board::insert(const position_t position)
{
    assert(mOrder.size() < (mWidth * mHeight));

    auto result = mPositions.insert(position);
    if (!result.second) {
        // std::set rejected this position as a duplicate.
        return false;
    }

    mOrder.push_back(position);

    assert(mOrder.size() == mPositions.size());

    return true;
}

void Board::pop_back()
{
    position_t item = mOrder.back();
    mPositions.erase(item);
    mOrder.pop_back();
    assert(mOrder.size() == mPositions.size());
}

std::optional<position_t> Board::latest() const
{
    if (mOrder.size()) {
        return mOrder.back();
    }

    return std::nullopt;
}

void Board::output() const
{
    std::vector<std::vector<uint32_t>> board(mWidth, std::vector<uint32_t>(mHeight, 0));

    assert(mOrder.size() <= (mWidth * mHeight));

    uint32_t step = 1;
    for (auto item : mOrder) {
        board[static_cast<unsigned>(item.first)][static_cast<unsigned>(item.second)] = step++;
    }

    for (auto row : board) {
        for (auto col : row) {
            if (col > 0) {
                std::cout << std::right << std::setw(3) << col;
            } else {
                std::cout << "   ";

            }
        }
        std::cout << std::endl;
    }
}

std::size_t Board::width() const
{
    return mWidth;
}

std::size_t Board::height() const
{
    return mHeight;
}

bool Board::isSolved() const
{
    return (mOrder.size() >= mWidth * mHeight);
}

} // namespace to25
