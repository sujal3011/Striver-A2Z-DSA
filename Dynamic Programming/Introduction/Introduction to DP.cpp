#include<bits/stdc++.h>
using namespace std;


//Memoization
//Time complexity--->O(N)
//Space complexity--->O(N)+O(N),recursive stack space and dp array
int fibonacci(int n,vector<int> &dp){

    if(n<=1) return n;
    if(dp[n]!=-1) return dp[n];

    return dp[n]=fibonacci(n-1,dp)+fibonacci(n-2,dp);
}

int main(){

    int n;
    cin>>n;
    vector<int>dp(n+1,-1);

    return 0;
}