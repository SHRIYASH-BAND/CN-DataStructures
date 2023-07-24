#include<iostream>
#include"PriorityQueue.h"
#include<queue>
using namespace std;

// K-Sorted array
void kSortedArray(int input[], int n, int k){
    priority_queue<int> pq;
    for(int i=0; i<k; i++)
        pq.push(input[i]);
    
    int j=0;
    for(int i =k; i<n; i++){
        input[j]= pq.top();
        pq.pop();
        pq.push(input[i]);
        j++;
    }

    while (!pq.empty())
    {
        input[j] = pq.top();
        pq.pop();
        j++;
    }
    
}


int main(){
    // building own priority queue.
    // PriorityQueue p;
    // p.print();
    // p.insert_MaxHeap(12);
    // p.insert_MaxHeap(6);
    // p.insert_MaxHeap(5);
    // p.insert_MaxHeap(100);
    // p.insert_MaxHeap(1);
    // p.insert_MaxHeap(9);
    // p.insert_MaxHeap(0);
    // p.insert_MaxHeap(14);
    // p.print();
    // cout<<"\n Max ele "<<p.getMax()<<endl;
    // p.removeMax();
    // p.print();
    // cout<<"\n Max ele "<<p.getMax()<<endl;
    // p.removeMax();
    // p.print();
    // p.insert_MaxHeap(30);
    // p.print();

    // Inbuilt priority queue
    int input[] = {10,12,6,7,9};
    int k=3;
    kSortedArray(input,5,k);
    for (int i = 0; i < 5; i++)
    {
        cout<<input[i]<<" ";
    }
    
    return 0;

}