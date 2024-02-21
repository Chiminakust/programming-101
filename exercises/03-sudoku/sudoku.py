"""Implements the game of sudoku."""

from enum import Enum
from random import randint
from math import sqrt

class GridValue(Enum):
    ZERO = 0
    ONE = 1
    TWO = 2
    THREE = 3
    FOUR = 4
    FIVE = 5
    SIX = 6
    SEVEN = 7
    EIGHT = 8
    NINE = 9

    def __repr__(self):
        if self.value > 0:
            return f'{self.value}'
        else:
            return ' '

    def __str__(self):
        return self.__repr__()

class SudokuGame:
    # square grid
    COLS = ROWS = 9
    COLSEP = ' | '

    def __init__(self):
        self.grid = [[GridValue(0) for i in range(self.COLS)] for j in range(self.ROWS)]

    def grid_set(self, val: GridValue, x: int, y: int):
        # TODO: later check if the set value makes sense
        self.grid[x][y] = val

    def grid_row_border_print(self):
        print(' ' * 2 + '-' * (self.ROWS * (len(self.COLSEP) + 1) + 1))

    def grid_header_print(self):
        labels = "ABCDEFGHI"
        print(' ' * (len(self.COLSEP) + 1), end='')
        for letter in labels:
            print(letter, end=' ' * len(self.COLSEP))
        print()

    def grid_print(self):
        print('GRID STATE:')
        self.grid_header_print()
        for x, row in enumerate(self.grid):
            self.grid_row_border_print()
            print(x, end=self.COLSEP)
            for y, col in enumerate(row):
                print(self.grid[x][y], end=self.COLSEP)
            print()

        self.grid_row_border_print()

    def grid_fill_random(self):
        for x, row in enumerate(self.grid):
            for y, col in enumerate(row):
                val = GridValue(randint(1, 9))
                self.grid_set(val, x, y)

    def valid_row(self, rownum: int):
        row = self.grid[rownum]
        return len(row) == len(set(row))

    def valid_col(self, colnum: int):
        col = [row[colnum] for row in self.grid]
        return len(col) == len(set(col))

    def square_bounds(self, x: int):
        # returns the lower and upper bounds of a square in the grid
        lim = int(sqrt(self.ROWS))
        xmin = x - x % lim
        return xmin, xmin + lim

    def valid_square(self, rownum: int, colnum: int):
        # get indices delimiting the square
        rowmin, rowmax = self.square_bounds(rownum)
        colmin, colmax = self.square_bounds(colnum)
        # flatten the square in a single list
        square = [item for row in self.grid[rowmin:rowmax] for item in row[colmin:colmax]]
        return len(square) == len(set(square))

def main():
    print("sudoku")
    game = SudokuGame()
    game.grid_fill_random()
    game.grid_print()


if __name__ == '__main__':
    main()
