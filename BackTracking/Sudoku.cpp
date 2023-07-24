#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

bool checkCol(vector<vector<int>> &sudoku, int colIndex, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (sudoku[i][colIndex] == num)
            return false;
    }

    return true;
}

bool checkRow(vector<vector<int>> &sudoku, int rowIndex, int num)
{
    for (int p = 0; p < 9; p++)
    {
        if (sudoku[rowIndex][p] == num)
            return false;
    }
    return true;
}

bool checkBox(vector<vector<int>> &sudoku, int rowIndex, int colIndex, int num)
{
    int rowFactor = rowIndex - (rowIndex % 3);
    int colFactor = colIndex - (colIndex % 3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (sudoku[i + rowFactor][j + colFactor] == num)
            {
                return false;
            }
        }
    }
    return true;
}

bool isSafe(vector<vector<int>> &sudoku, int rowIndex, int colIndex, int i)
{

    bool col = checkCol(sudoku, colIndex, i);
    bool row = checkRow(sudoku, rowIndex, i);
    bool box = checkBox(sudoku, rowIndex, colIndex, i);

    return col && row && box;
}

bool findEmptyLocation(vector<vector<int>> &sudoku, int &row, int &col)
{

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (sudoku[i][j] == 0)
            {
                row = i;
                col = j;
                return true;
            }
        }
    }

    return false;
}

bool solveSudoku(vector<vector<int>> &sudoku)
{

    int row, col;
    if (!findEmptyLocation(sudoku, row, col))
    {
        return true;
    }

    // check for all possible places
    for (int i = 1; i < 10; i++)
    {
        if (isSafe(sudoku, row, col, i))
        {
            sudoku[row][col] = i;
            if (solveSudoku(sudoku))
                return true;
            sudoku[row][col] = 0;
        }
    }

    return false;
}

int main()
{
    vector<vector<int>> sudoku;

    for (int i = 0; i < 9; i++)
    {
        string s;
        cin >> s;
        vector<int> v;
        for (int i = 0; i < s.length(); i++)
        {
            v.push_back(s[i] - 48);
        }
        sudoku.push_back(v);
    }

    solveSudoku(sudoku);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << sudoku[i][j];
        }
        cout << endl;
    }

    return 0;
}
