#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void print(vector<bool> &visited, vector<int> &parent, vector<int> &weight)
{

    for (int i = 1; i < visited.size(); i++)
    {
        if (i > parent[i])
        {
            cout << parent[i] << " " << i << " " << weight[i] << endl;
        }
        else
        {
            cout << i << " " << parent[i] << " " << weight[i] << endl;
        }
    }
}

void primsAlgo(vector<vector<int>> &graph, vector<bool> &visited, vector<int> &parent, vector<int> &weight)
{
    int v = visited.size();

    int i = 0;
    while (i < v)
    {
        int minWeight = INT_MAX;
        int minWeightVertex = 0;
        for (int z = 0; z < v; z++)
        {
            if (weight[z] < minWeight && !visited[z])
            {
                minWeight = weight[z];
                minWeightVertex = z;
            }
        }

        // marking the vertex as visited.
        visited[minWeightVertex] = true;

        //
        for (int p = 0; p < v; p++)
        {
            if (graph[minWeightVertex][p] != 0 && !visited[p] && weight[p] > graph[minWeightVertex][p])
            {
                parent[p] = minWeightVertex;
                weight[p] = graph[minWeightVertex][p];
            }
        }

        i++;
    }

    cout << " MST has edges as: " << endl;
    print(visited, parent, weight);
}

int main()
{
    int v, e;
    cin >> v >> e;

    vector<vector<int>> graph;
    for (int i = 0; i < v; i++)
    {
        vector<int> p;
        for (int j = 0; j < v; j++)
        {
            p.push_back(0);
        }

        graph.push_back(p);
    }

    for (int i = 0; i < e; i++)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        graph[v1][v2] = w;
        graph[v2][v1] = w;
    }

    vector<int> parent;
    vector<int> weight;
    vector<bool> visited;
    for (int i = 0; i < v; i++)
    {
        parent.push_back(-1);
        weight.push_back(INT_MAX);
        visited.push_back(false);
    }

    primsAlgo(graph, visited, parent, weight);
}

/*
5 7
0 1 4
0 2 8
1 3 6
1 2 2
2 3 3
2 4 9
3 4 5
*/