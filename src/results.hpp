#pragma once
#ifndef RESULTS_HPP
#define RESULTS_HPP

#include "resultbase.hpp"

class Results : public to25::ResultBase {

public:
    Results();

    void addSolved(const to25::Board& board) override;
    void addDeadEnd(const to25::Board& board) override;

    void printStats() const;

private:
    uint32_t mNumSolved;
    uint32_t mNumDeadEnds;
};

#endif
