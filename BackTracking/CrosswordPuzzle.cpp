#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool isValidVertical(char grid[][10], int row, int col, string word)
{
    int length = 0;
    int rowIndex = row;
    while (rowIndex < 10)
    {
        if (length > word.length())
            return false;
        if (grid[rowIndex][col] == '+')
        {
            break;
        }
        if (word[length] != grid[rowIndex][col] && grid[rowIndex][col] != '-')
        {
            return false;
        }
        rowIndex++;
        length++;
    }

    if (length < word.length())
        return false;

    return true;
}

bool isValidHorizontal(char grid[][10], int row, int col, string word)
{
    int length = 0;
    int colIndex = col;
    while (colIndex < 10)
    {
        if (length > word.length())
            return false;
        if (grid[row][colIndex] == '+')
        {
            break;
        }
        if (grid[row][colIndex] != '-' && word[length] != grid[row][colIndex])
        {
            return false;
        }
        colIndex++;
        length++;
    }

    if (length < word.length())
        return false;

    return true;
}

void setVertical(char grid[][10], int row, int col, string word, vector<int> &setName)
{
    for (int i = 0; i < word.length(); i++)
    {
        if (grid[row][col] == '-')
        {
            grid[row][col] = word[i];
            setName[i] = 1;
        }
        row++;
    }
}

void setHorizontal(char grid[][10], int row, int col, string word, vector<int> &setName)
{
    for (int i = 0; i < word.length(); i++)
    {
        if (grid[row][col] == '-')
        {
            grid[row][col] = word[i];
            setName[i] = 1;
        }
        col++;
    }
}

void resetVertical(char grid[][10], int row, int col, string word, vector<int> &setName)
{
    for (int i = 0; i < word.length(); i++)
    {
        if (setName[i] == 1)
        {
            grid[row][col] = '-';
            setName[i] = 0;
        }
        row++;
    }
}

void resetHorizontal(char grid[][10], int row, int col, string word, vector<int> &setName)
{
    for (int i = 0; i < word.length(); i++)
    {
        if (setName[i] == 1)
        {
            grid[row][col] = '-';
            setName[i] = 0;
        }
        col++;
    }
}

bool solveCrossword(char grid[][10], vector<string> &words, int p)
{
    if (p >= words.size())
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (grid[i][j] == '-')
                {
                    return false;
                }
            }
        }

        return true;
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (grid[i][j] == '-' || grid[i][j] == words[p].at(0))
            {
                if (isValidVertical(grid, i, j, words[p]))
                {
                    vector<int> setName(words[p].length());
                    setVertical(grid, i, j, words[p], setName);
                    if (!solveCrossword(grid, words, p + 1))
                    {
                        resetVertical(grid, i, j, words[p], setName);
                    }
                    else
                    {
                        return true;
                    }
                }

                if (isValidHorizontal(grid, i, j, words[p]))
                {
                    vector<int> setName(words[p].length());
                    setHorizontal(grid, i, j, words[p], setName);
                    if (!solveCrossword(grid, words, p + 1))
                    {
                        resetHorizontal(grid, i, j, words[p], setName);
                    }
                    else
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main()
{

    char grid[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> grid[i][j];
        }
    }

    vector<string> words;
    string s;
    cin >> s;

    for (int i = 0; i < s.length();)
    {
        string t;
        while (s[i] != ';' && i < s.length())
        {
            t += s[i];
            i++;
        }
        words.push_back(t);
        i++;
    }

    solveCrossword(grid, words, 0);

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }
    return 0;
}

/*
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV

+-++++++++
+-++++++++
+-++++++++
+-----++++
+-+++-++++
+-+++-++++
+++++-++++
++------++
+++++-++++
+++++-++++
LONDON;DELHI;ICELAND;ANKARA

+-++++++++
+-++++++++
+-------++
+-++++++++
+-++++++++
+------+++
+-+++-++++
+++++-++++
+++++-++++
++++++++++
AGRA;NORWAY;ENGLAND;GWALIOR

-----+++++
++++++++++
++++++++++
++++++++++
++++++++++
++++++++++
++++++++++
++++++++++
++++++++++
++++++++++
ROHAN

-----+++++
-+++++++++
-+++++++++
-+++++++++
++++++++++
++++++++++
++++++++++
++++++++++
++++++++++
++++++++++
RAVI;ROHAN
*/