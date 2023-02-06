#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define N 9;

bool possible(int &x, int &i, int &j, int grid[N][N])
{
    for (int k = 0; k < N; k++)
    {
        if (grid[i][k] == x || grid[k][j] == x)
            return false;
    }
    int s_i = (i / 3) * 3, s_j = (j / 3) * 3;
    for (int p = s_i; p < s_i + 3; p++)
    {
        for (int q = s_j; q < s_j + 3; q++)
        {
            if (grid[p][q] == x)
                return false;
        }
    }
    return true;
}
bool rec(int i, int j, int grid[N][N])
{
    if (i == N - 1 && j == N)
        return true;
    if (j == N)
    {
        i++;
        j = 0;
    }
    if (grid[i][j] == 0)
    {
        bool flag = 0;
        for (int x = 1; x <= 9; x++)
        {
            if (possible(x, i, j, grid))
            {
                flag = 1;
                grid[i][j] = x;
                if (rec(i, j + 1, grid))
                    return true;
                grid[i][j] = 0;
            }
        }
        if (!flag)
            return false;
    }
    else
        rec(i, j + 1, grid);
}
bool SolveSudoku(int grid[N][N])
{
    // Your code here
    return rec(0, 0, grid);
}

// Function to print grids of the Sudoku.
void printGrid(int grid[N][N])
{
    // Your code here
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << grid[i][j] << ' ';
    }
}