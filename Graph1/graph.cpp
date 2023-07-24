#include <iostream>
#include <queue>

using namespace std;

void print_DFS(int **edges, int n, int start, bool *visited)
{

    cout << start << " ";
    visited[start] = true;
    for (int i = 0; i < n; i++)
    {
        if (start == i)
            continue;
        if (edges[start][i] == 1 && !visited[i])
        {
            print_DFS(edges, n, i, visited);
        }
    }
}

void print_DFS(int **edges, int n, bool *visited)
{

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            print_DFS(edges, n, i, visited);
        }
    }

    return;
}

void print_BFS(int **edges, int n, int i, bool *&visited)
{
    queue<int> q;
    q.push(i);
    visited[i] = true;
    while (!q.empty())
    {
        cout << q.front() << " ";

        for (int z = 0; z < n; z++)
        {
            if (i == z)
                continue;
            if (edges[q.front()][z] == 1 && !visited[z])
            {
                visited[z] = true;
                q.push(z);
            }
        }
        q.pop();
    }
}

void print_BFS(int **edges, int n, bool *visited)
{

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            print_BFS(edges, n, i, visited);
        }
    }

    return;
}

int main()
{
    int n, e;
    cin >> n >> e;

    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    cout << endl
         << "Vertices of Graph in DFS are: ";
    print_DFS(edges, n, visited);
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    cout << endl
         << "Vertices of Graph in BFS are: ";
    print_BFS(edges, n, visited);
    // free memory

    for (int i = 0; i < n; i++)
        delete[] edges[i];
    delete[] edges;
    delete[] visited;

    return 0;
}