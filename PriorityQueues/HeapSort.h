// In-place Heap Sort i.e space complex = O(1)
#include<iostream>
using namespace std;

void sortDesc(int* arr, int n){
    // Descending In-Place Heap Sort uses Min-Heap
    if (n<2)
       return;
    
    // up-Heapify
    int i=1;
    while (i<n)
    {
        int childIndex = i-1;
        int parentIndex = (childIndex-1)/2;
        while (childIndex>0)
        {
            if(arr[parentIndex]>arr[childIndex]){
                swap(arr[parentIndex],arr[childIndex]);
                childIndex = parentIndex;
            }
            else
                break;
        }

        i++;   
    }   

    // down-heapify
    i = n-1;
    while (i>0)
    {

        swap(arr[0],arr[i]);
        int parentIndex = 0;
        while (parentIndex<i)
        {
            int child1Index = 2*parentIndex +1;
            int child2Index = 2* parentIndex +2;
            int minIndex=0;
            if(child1Index<i && child2Index<i){
                minIndex = (arr[child1Index]<=arr[child2Index])  ? child1Index : child2Index ;
            }
            else if(child1Index<i){
                minIndex = child1Index;
            }
            else{
                break;
            }

            if(arr[minIndex]<arr[parentIndex]){
                swap(arr[minIndex],arr[parentIndex]);
            }
            else
                break;

            parentIndex = minIndex;
        }
        i--;        
    }  
}

void sortAsce(int* arr, int n){
    //Ascending In-place  heap sort uses Max Heap 
    if(n<2)
        return;
    
    // up-heapify
    for(int i=1; i<n; i++){
        int childIndex = i;
        while (childIndex>0)
        {
            int parentIndex = (childIndex-1)/2;
            if(arr[parentIndex]<arr[childIndex]){
                swap(arr[parentIndex], arr[childIndex]);
                childIndex = parentIndex;
            }
            else
                break;
        } 
    }

    // down heapify
    for(int i=n-1; i>0; i--){
        swap(arr[0],arr[i]);
        int parentIndex = 0;
        while (parentIndex<i)
        {
            int child1Index = 2*parentIndex +1;
            int child2Index = 2*parentIndex + 2;
            int maxIndex =0;
            if(child1Index<i && child2Index<i){
                maxIndex = (arr[child1Index]>=arr[child2Index])? child1Index : child2Index;
            }
            else if(child1Index<i){
                maxIndex = child1Index;
            }
            else
                break;
            
            if(arr[maxIndex]>arr[parentIndex]){
                swap(arr[maxIndex],arr[parentIndex]);
            }
            else
                break;
            
            parentIndex = maxIndex;
        }
        
    }
}

