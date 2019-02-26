#pragma once
#ifndef RESULTBASE_HPP
#define RESULTBASE_HPP

#include "board.hpp"

namespace to25 {

class ResultBase {

public:
    virtual void addSolved(const Board& board) = 0;
    virtual void addDeadEnd(const Board& board) = 0;
};

} // namespace to25

#endif
