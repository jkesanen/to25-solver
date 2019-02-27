#include "gtest/gtest.h"

#include "board.hpp"

TEST (BoardTest, Latest) {
    to25::Board gameboard(5, 5);

    gameboard.insert(to25::position_t{ 1, 1 });
    gameboard.insert(to25::position_t{ 3, 5 });

    const to25::position_t pos{ 2, 2 };
    gameboard.insert(pos);

    auto latest = gameboard.latest();

    ASSERT_TRUE(latest.has_value());

    EXPECT_EQ(latest.value().first, pos.first);
    EXPECT_EQ(latest.value().second, pos.second);
}

TEST(BoardTest, LatestOnEmpty)
{
    to25::Board gameboard(15, 15);

    auto latest = gameboard.latest();

    ASSERT_FALSE(latest.has_value());
}

TEST(BoardTest, Duplicate)
{
    to25::Board gameboard(5, 5);

    const to25::position_t pos{ 1, 2 };

    ASSERT_TRUE(gameboard.insert(pos));
    ASSERT_FALSE(gameboard.insert(pos));
}
