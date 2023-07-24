#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <chrono>
#include "Edge.h"

using namespace std;
using namespace std::chrono;


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

// Union Find Cycle Detection Method with time complex as O(v);

// Find 
int findParent( int v, vector<int>& parent ){
    if( parent[v] == v ){
        return v;
    }

    return findParent( parent[v], parent );
}

void kruskal(vector<Edge> &input, vector<int> &parent, int v)
{
    vector<Edge> output;
    int count = 0;
    int i = 0;
    while (count < (v - 1))
    {
        int v1 = input[i].getSource(), v2 = input[i].getDestination();
        int p1 = findParent( v1, parent ), p2 = findParent( v2, parent );
        if (  p1 != p2 )
        {
            output.push_back(input[i]);
            // Union 
            parent[p2] = p1;
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

    vector<int> parent;
    for (int i = 0; i < v; i++)
    {
        parent.push_back(i);
    }

    auto start = high_resolution_clock::now();
    
    cout << " MST for graph inludes edges: " << endl;
    kruskal(input, parent, v);

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