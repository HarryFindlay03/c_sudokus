#include "brute.h"

int main()
{
    int test[9][9] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };

    printf("\n");

    printf("UNSOLVED\n");
    output_sudoku(test);
    printf("\n\n");

    if(solve(test, 0, 0))
    {
        printf("SOLVED\n");
        output_sudoku(test);
    }
    else
        printf("CANNOT SOLVE\n");
    
    printf("\n");
    return 0;
}

/**
 * Take a partially unsolved suduko and attempts to find solution using
 * backtracking - this is a recursive solution
 */
int solve(int arr[9][9], int row, int col)
{
    if(row == 8 && col == 9)
        return 1;

    if(col == 9)
    {
        row++;
        col = 0;
    }

    // if the current position contains a value greater than 0
    // recursively move to the next position
    if(arr[row][col] > 0)
        return solve(arr, row, col + 1);

    int i;
    for(i = 0; i <= 9; i++)
    {
        // check that it is safe to palce given i in the position
        if(valid(arr, row, col, i))
        {
            // assigning number in given position in the arr
            arr[row][col] = i;

            if(solve(arr, row, col + 1))
                return 1;
        }
        // removing the assigned number as it does not fit into the correct solution
        arr[row][col] = 0;
    }
    return 0;
}

/**
 * Checks whether suduko with filled in number is valud
 */
int valid(int arr[9][9], int row, int col, int num)
{
    int i, j;

    // checking if we find duplicate num in row
    for(i = 0; i < 9; i++)
        if(arr[row][i] == num)
            return 0;

    // checking if we find duplicate in col
    for(i = 0; i < 9; i++)
        if(arr[i][col] == num)
            return 0;
    
    // checking if we find duplicate in box
    int rowStart = row - row % 3;
    int colStart = col - col % 3;

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            if(arr[rowStart + i][colStart + j] == num)
                return 0;
        }
    }
    
    // passes all the tests
    return 1;
}

void output_sudoku(int arr[9][9])
{
    int i, j;
    for(i = 0; i < 9; i++)
    {
        for(j = 0; j < 9; j++)
        {
            printf("%d ", arr[i][j]);
            if(((j + 1) % 3) == 0 && j != 0 && j < 8)
                printf("| ");
        }
        if(((i + 1) % 3) == 0 && i != 0 && i < 8)
            printf("\n---------------------");
        printf("\n");
    }
}
