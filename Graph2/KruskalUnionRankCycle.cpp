#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <chrono>
#include <vector>
#include "Edge.h"

using namespace std;
using namespace std::chrono;

struct subset {
    int parent;
    int rank;
};

// A utility function to find set of an element i
// (uses path compression technique)
int find(struct subset subsets[], int i)
{
    // find root and make root as parent of i (path
    // compression)
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
 
    return subsets[i].parent;
}

// A function that does union of two sets of x and y
// (uses union by rank)
void Union(struct subset subsets[], int xroot, int yroot)
{
 
    // Attach smaller rank tree under root of high rank tree
    // (Union by Rank)
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
 
    // If ranks are same, then make one as root and
    // increment its rank by one
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

bool compareWeight(Edge e1, Edge e2)
{
    return e1.getWeight() < e2.getWeight();
}

void print(vector<Edge> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        int v1, v2;
        if (v[i].getSource() > v[i].getDestination())
        {
            v1 = v[i].getDestination();
            v2 = v[i].getSource();
        }
        else
        {
            v1 = v[i].getSource();
            v2 = v[i].getDestination();
        }
        cout << v1 << " " << v2 << " " << v[i].getWeight() << endl;
    }
}

// Union Find Cycle Detection Method with time complex as O(logv);

void kruskal(vector<Edge> &input, int v)
{
    vector<Edge> output;
    int count = 0;
    int i = 0;
    struct subset* subsets
        = (struct subset*)malloc(v * sizeof(struct subset));
 
    for (int i = 0; i < v; ++i) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    while (count < (v - 1))
    {
        int v1 = input[i].getSource(), v2 = input[i].getDestination();
        int p1 = find(subsets,v1), p2 = find( subsets, v2);
        if (  p1 != p2 )
        {
            output.push_back(input[i]);
            // Union 
            Union(subsets, p1, p2);
            count++;
        }
        i++;
    }

    print(output);
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<Edge> input;

    // Take input
    for (int i = 0; i < e; i++)
    {
        int v1, v2, weight;
        cin >> v1 >> v2 >> weight;
        Edge eg(v1, v2, weight);
        input.push_back(eg);
    }

    // sort input array
    sort(input.begin(), input.end(), compareWeight);

    auto start = high_resolution_clock::now();

    cout << " MST for graph inludes edges: " << endl;
    kruskal(input, v);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start); 
    cout << duration.count() << endl;

    return 0;
}

/*
6 11
0 1 1
0 2 5
2 3 10
0 3 4
1 3 3
1 2 6
3 4 7
2 4 8
4 5 2
2 5 9
3 5 6

6 11
1 3 1
0 1 2
0 3 3
0 2 4
4 5 5
2 3 6
3 5 7
2 1 8
2 4 9
2 5 10
3 4 11

9 14
7 6 1
8 2 2
6 5 2
0 1 4
2 5 4
8 6 6
2 3 7
7 8 7
0 7 8
1 2 8
3 4 9
5 4 10
1 7 11
3 5 14 
*/