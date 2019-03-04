#pragma once
#ifndef RESULTS_HPP
#define RESULTS_HPP

#include "resultbase.hpp"

class Results : public to25::ResultBase {

public:
    void addSolved(const to25::Board& board) override;
    void addDeadEnd(const to25::Board& board) override;

    void printStats() const;

private:
    uint32_t mNumSolved{0};
    uint32_t mNumDeadEnds{0};
};

#endif
