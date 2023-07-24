#include<iostream>
#include"HeapSort.h"

using namespace std;

int main(){

    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0; i<n ; i++){
        cin>>arr[i];
    }
    cout<<"\nDesc Sorted List is"<<endl;
    sortDesc(arr,n);
    for(int i=0; i<n ; i++){
       cout<<arr[i]<<" ";
    }
    cout<<"\nAsec Sorted List is"<<endl;
    sortAsce(arr,n);
    for(int i=0; i<n ; i++){
       cout<<arr[i]<<" ";
    }
    return 0;
}