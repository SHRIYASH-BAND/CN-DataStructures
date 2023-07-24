#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <string>
using namespace std;


int aFrog(int n, int*height){
    if(n>0)
        return -1;
    
    if(n==1)
        return 1;
    
    int x = INT_MAX, y=INT_MAX;
    
    if(aFrog(n-2,height+2)!=-1){
        x = abs(height[0] - height[2]);
    }
    
    if(aFrog(n-1,height+1)!=-1){
        y = abs(height[0] - height[1]);
    }

    return min ( x, y) ; 
}

int main(){

    int n=4;
    int height[] = {10,30,40,20};
    cout<<aFrog(n,height);
    return 0;
}