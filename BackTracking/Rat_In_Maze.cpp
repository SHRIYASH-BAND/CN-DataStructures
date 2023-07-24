/*
    Note:
    To get all the test cases accepted, make recursive calls in following order: Top, Down, Left, Right.
    This means that if the current cell is (x, y), then order of calls should be: top cell (x-1, y),
    down cell (x+1, y), left cell (x, y-1) and right cell (x, y+1).
*/
#include <bits/stdc++.h>
using namespace std;

void mazeSolution(vector<vector<int>> &maze, vector<vector<int>> &path, int rowIndex, int colIndex)
{

    if (rowIndex == colIndex && rowIndex == maze.size() - 1)
    {
        // print solution
        path[rowIndex][colIndex] = 1;

        for (int i = 0; i < path.size(); i++)
        {
            for (int j = 0; j < path[0].size(); j++)
            {
                cout << path[i][j] << " ";
            }
        }
        cout << endl;
        path[rowIndex][colIndex] = 0;
        return;
    }

    // out of boundary move
    if (rowIndex < 0 || colIndex < 0 || rowIndex == maze.size() || colIndex == maze.size())
    {
        return;
    }

    // dead cell or path discovered
    if (maze[rowIndex][colIndex] == 0 || path[rowIndex][colIndex] == 1)
    {
        return;
    }

    // recursion
    path[rowIndex][colIndex] = 1;
    // top cells checking
    mazeSolution(maze, path, rowIndex - 1, colIndex);
    // down cells checking
    mazeSolution(maze, path, rowIndex + 1, colIndex);
    // left cells checking
    mazeSolution(maze, path, rowIndex, colIndex - 1);
    // right cells checking
    mazeSolution(maze, path, rowIndex, colIndex + 1);

    path[rowIndex][colIndex] = 0;
}

int main()
{

    int n = 0;
    cin >> n;
    vector<vector<int>> maze(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int cellValue = 0;
            cin >> cellValue;
            maze[i].push_back(cellValue);
        }
    }

    vector<vector<int>> path(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            path[i].push_back(0);
        }
    }

    mazeSolution(maze, path, 0, 0);
    return 0;
}
