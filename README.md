# to25-solver

Solves `To 25` games.

## The game

As I don't know the name of this game, which I learned in elementary school from a classmate, I'll call it "To 25". The game is played on a **5x5** board of squares. You'll try to fill in the numbers from 1 to 25 while following the game's rules.

The best occasion to play this game is while you should be paying attention to something more important. You'll most likely play this game into the free margins of cross-ruled papers.

In the picture below there are some played dead-end games and a solved game:

![To 25 games](https://jkesanen.github.io/to25/to25.jpg)

With the combination of the games in the picture and the rules below, you should be able to understand how to play "To 25".

## Game rules

* A board of 5 x 5 squares.
* Number 1 is written to the top-left corner.
* The next number (increment by one) goes into a free square, which is either:
  * 3 squares up, down, left OR right from the current number (skip two squares).
  * 2 squares diagonally from the current number (skip one square).
* By following these rules you'll try to get to number 25 by filling all the squares on the board.

## Solver

This solver tries to go through all the possible combinations of numbers by following the rules. All the solved boards (no empty squares, 25 reached) are printed. At the end the number of solving combinations and dead-end games are printed.

## Why?

* I remembered this simple game and wanted to find out the number of possible winning combinations.
* Wanted to document the game and its rules somewhere. Perhaps someone finds it good fun.
* Took the opportunity to check out some new C++17 features.
* Brushed up my CMake knowledge by reading several blog posts regarding "Modern CMake".
