#include <bits/stdc++.h>
using namespace std;

bool isPosition(vector<vector<int>> &matrix, int rowIndex, int colIndex)
{
    // check col;
    for (int i = 0; i <= rowIndex; i++)
    {
        if (matrix[i][colIndex] == 1)
            return false;
    }

    // check left diagonal
    int rowCheck = rowIndex;
    int colCheck = colIndex;
    while (colCheck >= 0 && rowCheck >= 0)
    {
        if (matrix[rowCheck][colCheck] == 1)
            return false;
        colCheck--;
        rowCheck--;
    }

    // check right diagonal
    rowCheck = rowIndex;
    colCheck = colIndex;
    while (colCheck <= matrix[0].size() && rowCheck >= 0)
    {
        if (matrix[rowCheck][colCheck] == 1)
            return false;
        rowCheck--;
        colCheck++;
    }

    return true;
}

void printSolution(vector<vector<int>> &matrix, int rowIndex)
{

    if (rowIndex >= matrix.size())
    {
        // print solution
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                cout << matrix[i][j] << " ";
            }
        }
        cout << endl;
        return;
    }

    int colIndex = 0;
    while (colIndex < matrix[0].size())
    {
        if (isPosition(matrix, rowIndex, colIndex))
        {
            matrix[rowIndex][colIndex] = 1;
            printSolution(matrix, rowIndex + 1);
            matrix[rowIndex][colIndex] = 0;
        }
        colIndex++;
    }
}
int main()
{

    int n = 0;
    cin >> n;
    cout << endl;
    vector<vector<int>> matrix(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i].push_back(0);
        }
    }

    printSolution(matrix, 0);

    return 0;
}