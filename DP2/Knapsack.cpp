#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int knapsack(int *weights, int *values, int n, int maxWeight)
{
	if(n==0 ||  maxWeight<=0){
		return 0;
	}
	
	int x=INT_MIN;
	if(maxWeight-weights[0]>=0)
		x = knapsack(weights+1, values+1, n-1, maxWeight-weights[0]) + values[0];
	int y = knapsack(weights+1, values+1, n-1, maxWeight);

	return max(x,y);
}

int knapsack_Memo(int* weight, int* value, int n, int maxWeight, int* output){
	// if( ){
	// 	output[0] = 0;
	// 	return output[0];
	// }
    if(n==0 || maxWeight<=0)
        return 0;

	if(output[0]!=-1){
		return output[0];
	}

	int x = INT_MIN;
	if(maxWeight-weight[0]>=0){
		x = knapsack_Memo(weight+1, value+1, n-1, maxWeight - weight[0], output+1) + value[0];
	}
	int y = knapsack_Memo(weight+1, value+1, n-1, maxWeight, output+1);

	output[0] = max(x,y);
	return output[0];
}

int main(){

    int weight[] = {12,7,11,8,9};
    int value[] = {24,13,23,15,16};
    int n=5;
    int maxWeight = 26;

    cout<<knapsack(weight,value,n,maxWeight)<<endl;

    int output[5];
	for(int i=0; i<n; i++)
		output[i]=-1;
	
	cout<<knapsack_Memo(weight, value, n, maxWeight, output)<<endl;

    return 0;
}