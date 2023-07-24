#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <string>
using namespace std;


int editDistance_DP(string s, string t) {
	int ** output = new int*[s.length()+1];
    for(int i=0; i<=s.length(); i++){
        output[i] = new int[t.length()+1];
    }

    for(int i=0; i<=s.length(); i++){
        for(int j=0; j<=t.length(); j++){
            output[i][j] = -1;
        }
    }
    int m = s.length();
    int n= t.length();

    for(int i=0; i<=m; i++){
        output[i][0] = i;
    }

    for(int j=1; j<=n; j++){
        output[0][j] = j;
    }
    
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(s[m-i]==t[n-j]){
                output[i][j] = output[i-1][j-1];
            }
            else
                output[i][j] = min (output[i-1][j-1], min(output[i][j-1], output[i-1][j])) +1;
        }
    }

    int ans = output[m][n];

    for(int i=0; i<=s.length(); i++){
        delete [] output[i];
    }
    delete [] output;
    return ans;
}

int editDistance_Memo(string s, string t, int**& output){
    int m = s.length();
    int n= t.length();
    if(m==0 || n==0){
            output[m][n] = m+n;
            return output[m][n];
    }

    if(output[m][n]!=-1)
        return output[m][n];

    if(s[0]==t[0]){
        output[m][n] = editDistance_Memo(s.substr(1), t.substr(1), output);
    }
    else{
        int x = editDistance_Memo(s, t.substr(1), output);
        int y = editDistance_Memo(s.substr(1), t, output);
        int z = editDistance_Memo(s.substr(1), t.substr(1), output);

        output[m][n] = min(x, min(y,z)) +1;
    }

    return output[m][n];
}

int editDistance(string s, string t)
{
    // base case
    if (s.length() == 0 || t.length() == 0)
    {
        return max(s.length(), t.length());
    }

    if (s[0] == t[0])
    {
        return editDistance(s.substr(1), t.substr(1));
    }
    else
    {
        int x = editDistance(s, t.substr(1)) + 1;
        int y = editDistance(s.substr(1), t) + 1;
        int z = editDistance(s.substr(1), t.substr(1)) + 1;

        return min(x, min(y, z));
    }
}

int main()
{

    string s, t;
    cin >> s >> t;
    cout <<"\n Brute Force "<< editDistance(s, t)<<endl;

    int ** output = new int*[s.length()+1];
    for(int i=0; i<=s.length(); i++){
        output[i] = new int[t.length()+1];
    }

    for(int i=0; i<=s.length(); i++){
        for(int j=0; j<=t.length(); j++){
            output[i][j] = -1;
        }
    }
    cout<<"\n Memoization "<<editDistance_Memo(s,t,output)<<endl;

    for(int i=0; i<=s.length(); i++){
        delete [] output[i];
    }
    delete [] output;

    cout<<" \n DP "<<editDistance_DP(s,t)<<endl;
    return 0;
}