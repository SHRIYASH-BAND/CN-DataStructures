#include<iostream>
#include<bits/stdc++.h>
#include<unordered_map>
#include<math.h>
#include<string>
using namespace std;



int lcs_DP(string s, string t){
    int **output = new int*[s.length()+1];
    for(int i=0; i<s.length()+1; i++){
        output[i] = new int[t.length()+1];
    }

    for(int i=0; i<=s.length(); i++){
        for(int j=0; j<=t.length(); j++){
            output[i][j]=-1;
        }
    }

    //iterative / DP
    for(int i=0; i<=s.length(); i++){
        output[i][0] = 0;
    }
    
    for(int i=0; i<=t.length(); i++){
        output[0][i] = 0;
    }
    
    for(int i=1; i<=s.length(); i++){
        for(int j=1; j<=t.length(); j++){

            if(i==s.length() && j==t.length()){
                output[i][j] =0; 
            }
            else if(s[i]!=t[j]){
                int x = output[i][j-1];
                int y = output[i-1][j];
                int z = output[i-1][j-1];
                output[i][j] = max(x, max(y,z));
            }
            else{
                output[i][j] = output[i-1][j-1] + 1;
            }

        }
    }

    int ans = output[s.length()][t.length()];
    for(int i=0; i<s.length(); i++){
        delete []output[i];
    }
    delete[] output;

    return ans;

}

int lcs_Memoized(string s, string t, int**& output){
    if(s.length()==0 || t.length()==0){
        output[s.length()][t.length()] = 0;
        return output[s.length()][t.length()];
    }

    if(output[s.length()][t.length()]!=-1)
        return output[s.length()][t.length()];

    int ans;
    if(s[0]!=t[0]){
        int x = lcs_Memoized(s,t.substr(1),output);
        int y = lcs_Memoized(s.substr(1), t,output);
        ans = max(x, y);
    }
    else{
        ans = lcs_Memoized(s.substr(1), t.substr(1),output) + 1;
    }

    output[s.length()][t.length()] = ans;
    return output[s.length()][t.length()];
}

int lcs(string s, string t){
    if(s.length()==0 || t.length()==0){
        return 0;
    }

    if(s[0]!=t[0]){
        int x = lcs(s,t.substr(1));
        int y = lcs (s.substr(1), t);
        int z = lcs (s.substr(1), t.substr(1));
        return max(x, max(y,z));
    }
    else{
        return lcs(s.substr(1), t.substr(1)) + 1;
    }
}

int main(){
    string s,t;
    cin>>s>>t;
    
    cout<<"\nRecursive LCS: "<<lcs(s,t);
    int **output = new int*[s.length()+1];
    for(int i=0; i<s.length()+1; i++){
        output[i] = new int[t.length()+1];
    }

    for(int i=0; i<=s.length(); i++){
        for(int j=0; j<=t.length(); j++){
            output[i][j]=-1;
        }
    }

    cout<<"\nMemoization LCS: "<<lcs_Memoized(s,t,output);

    for(int i=0; i<s.length(); i++){
        delete []output[i];
    }
    delete[] output;

    cout<<"\nDP LCS: "<<lcs_DP(s,t);
    return 0;
}