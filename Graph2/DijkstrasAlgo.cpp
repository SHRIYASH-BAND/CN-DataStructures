#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findMinDistVert(vector<int> &distance, vector<bool> &visited)
{
    int minDist = INT_MAX;
    int minVert = 0;
    int v = visited.size();
    for (int i = 0; i < v; i++)
    {
        if (distance[i] < minDist && !visited[i])
        {
            minDist = distance[i];
            minVert = i;
        }
    }

    return minVert;
}

void dijkstrasAlgo(vector<vector<int>> &graph, vector<int> &distance, vector<bool> &visited)
{

    int v = visited.size();
    distance[0] = 0;

    for (int i = 0; i < v - 1; i++)
    {

        // find min Distance
        int minDistanceVertex = findMinDistVert(distance, visited);

        visited[minDistanceVertex] = true;
        // find and update neighbors.
        for (int p = 0; p < v; p++)
        {
            if (graph[minDistanceVertex][p] != 0 && !visited[p])
            {
                if ((graph[minDistanceVertex][p] + distance[minDistanceVertex]) < distance[p])
                {
                    distance[p] = graph[minDistanceVertex][p] + distance[minDistanceVertex];
                }
            }
        }
    }
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

    vector<int> distance;
    vector<bool> visited;
    for (int i = 0; i < v; i++)
    {
        distance.push_back(INT_MAX);
        visited.push_back(false);
    }

    dijkstrasAlgo(graph, distance, visited);

    for (int i = 0; i < distance.size(); i++)
    {
        cout << i << " " << distance[i] << endl;
    }
}