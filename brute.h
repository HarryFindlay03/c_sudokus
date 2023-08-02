#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// How to represent the suduko - 2D array
// How to represent a partial solution - 2D array with the numbers filled in and 0 at the rest
// How to place at a cell - Look for the first empty cell
// Accepting a solution - Check the constraints whether number is on row and column or in box

int solve(int [9][9], int, int);
int valid(int [9][9], int, int, int);
void output_sudoku(int [9][9]);

