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

    @staticmethod
    def full_set():
        return set([GridValue(x) for x in range(1, 10)])

class SudokuGame:
    # square grid
    COLS = ROWS = 9
    COLSEP = ' | '

    def __init__(self):
        self.grid = [[GridValue(0) for i in range(self.COLS)] for j in range(self.ROWS)]

    def grid_set(self, val: int, x: int, y: int):
        # TODO: later check if the set value makes sense
        self.grid[x][y] = GridValue(val)

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

    def iter_rows(self):
        for row in self.grid:
            yield row

    def iter_cols(self):
        for colnum in range(self.COLS):
            yield [row[colnum] for row in self.grid]

    def iter_squares(self):
        for rownum in range(0, self.ROWS, int(sqrt(self.ROWS))):
            for colnum in range(0, self.COLS, int(sqrt(self.COLS))):
                rowmin, rowmax = self.square_bounds(rownum)
                colmin, colmax = self.square_bounds(colnum)
                yield [item for row in self.grid[rowmin:rowmax] for item in row[colmin:colmax]]

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

class SudokuStep:
    def __init__(self, value: GridValue, row: int, col: int):
        self.value = value
        self.row = row
        self.col = col

class SudokuSolver:
    def __init__(self):
        pass

    def get_nonempty_set(self, iterable):
        return set(iterable) - set([GridValue(0)])

    def step(self, game: SudokuGame) -> SudokuStep:
        """Returns the next move to play that advances the game."""

        # check for rows/cols/square that only miss 1 value
        for row in game.iter_rows():
            rowset = self.get_nonempty_set(row)
            if len(rowset) == len(row) - 1:
                missing = GridValue.full_set() - rowset
                print("missing value:", missing)

        for col in game.iter_cols():
            colset = self.get_nonempty_set(col)
            if len(colset) == len(col) - 1:
                missing = GridValue.full_set() - colset
                print("missing value:", missing)

        for square in game.iter_squares():
            squareset = self.get_nonempty_set(square)
            if len(squareset) == len(square) - 1:
                missing = GridValue.full_set() - squareset
                print("missing value:", missing)

    #def solve_missing_one(self, )


def make_game_easy():
    game = SudokuGame()

    game.grid_set(9, 0, 0)
    game.grid_set(3, 0, 1)
    game.grid_set(8, 0, 3)
    game.grid_set(6, 0, 5)
    game.grid_set(4, 0, 6)
    game.grid_set(5, 0, 7)
    game.grid_set(1, 0, 8)

    game.grid_set(1, 1, 0)
    game.grid_set(7, 1, 1)
    game.grid_set(2, 1, 8)

    game.grid_set(4, 2, 0)
    game.grid_set(6, 2, 1)
    game.grid_set(9, 2, 3)
    game.grid_set(1, 2, 4)
    game.grid_set(2, 2, 5)
    game.grid_set(8, 2, 6)
    game.grid_set(7, 2, 7)

    game.grid_set(2, 3, 0)
    game.grid_set(4, 3, 2)
    game.grid_set(7, 3, 3)
    game.grid_set(8, 3, 5)

    game.grid_set(8, 4, 0)
    game.grid_set(5, 4, 8)

    game.grid_set(6, 5, 2)
    game.grid_set(1, 5, 3)
    game.grid_set(3, 5, 4)
    game.grid_set(4, 5, 7)

    game.grid_set(6, 6, 0)
    game.grid_set(3, 6, 6)
    game.grid_set(8, 6, 7)

    game.grid_set(1, 7, 2)
    game.grid_set(3, 7, 5)

    game.grid_set(2, 8, 3)
    game.grid_set(8, 8, 4)
    game.grid_set(5, 8, 6)
    game.grid_set(6, 8, 8)

    return game

def main():
    print("sudoku")
    #game = SudokuGame()
    #game.grid_fill_random()
    game = make_game_easy()


    solver = SudokuSolver()
    game.grid_set(2, 0, 2)
    game.grid_print()
    step = solver.step(game)

    print(step)


if __name__ == '__main__':
    main()
