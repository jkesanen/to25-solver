#include <iostream>

#include "results.hpp"

Results::Results() :
    mNumSolved(0),
    mNumDeadEnds(0)
{};

void Results::addSolved(const to25::Board& board)
{
    mNumSolved++;
    std::cout << "----------------" << std::endl;
    board.output();
}

void Results::addDeadEnd([[maybe_unused]] const to25::Board& board)
{
    mNumDeadEnds++;
};

void Results::printStats() const
{
    std::cout << "----------------" << std::endl;
    std::cout << "Solved: " << mNumSolved << std::endl;
    std::cout << "Dead ends: " << mNumDeadEnds << std::endl;
    std::cout << "----------------" << std::endl;
}