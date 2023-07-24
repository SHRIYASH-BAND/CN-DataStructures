#include <iostream>
#include <unordered_map>
#include "ourmap.h"
#include <string>
#include <vector>
using namespace std;

vector<int> removeDuplicates(int *arr, int size)
{

    unordered_map<int, bool> seen;
    vector<int> output;

    for (int i = 0; i < size; i++)
    {
        if (seen.count(arr[i]) > 0)
        {
            continue;
        }
        seen[arr[i]] = true;
        output.push_back(arr[i]);
    }

    return output;
}

int main()
{
    int arr[] = {2, 3, 3, 4, 2, 5, 1, 6, 1, 5, 5};

    // vector<int> v = removeDuplicates(arr,11);

    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout<<v[i]<<" ";
    // }

    ourmap<int> mp;

    // key abc1--> value 1
    // key abc2--> value 2......
    for (int i = 0; i < 10; i++)
    {
        string s = "abc";
        string key = s + to_string(i + 1);
        mp.insert(key, i + 1);
        cout << mp.getLoadFactor() << endl;
    }

    mp.remove("abc2");
    mp.remove("abc7");
    // print
    for (int i = 0; i < 10; i++)
    {
        string s = "abc";
        string key = s + to_string(i + 1);
        cout << mp.getValue(key) << endl;
    }
}