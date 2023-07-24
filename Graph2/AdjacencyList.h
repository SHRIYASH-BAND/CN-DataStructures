#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class AdjacencyList
{
private:
    int vertex;
    vector<int> *edges;

public:
    AdjacencyList()
    {
        this->vertex = -1;
        this->edges = nullptr;
    }

    AdjacencyList(int vertex)
    {
        this->vertex = vertex;
        this->edges = nullptr;
    }

    AdjacencyList(int vertex, vector<int> *&edges)
    {
        this->vertex = vertex;
        this->edges = edges;
    }

    ~AdjacencyList()
    {
        delete edges;
    }

    int getVertex()
    {
        return this->vertex;
    }

    int getEdge(int pos)
    {
        return edges->at(pos);
    }

    vector<int> *getEdges()
    {
        return this->edges;
    }
};
