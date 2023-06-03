#include<bits/stdc++.h>
using namespace std;


//Memoization solution
//Time complexity--->O(N)
//Space complexity--->O(N)+O(N),recursive stack space and dp array
int func(int n,vector<int> &dp){
        if(n<=1) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=func(n-1,dp)+func(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return func(n,dp);
}


//Tabulation solution
//Time complexity--->O(N)
//Space complexity--->O(N),for dp array
int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
}


//Space optmized Tabulation solution
//Time complexity--->O(N)
//Space complexity--->O(1)
int climbStairs(int n) {
        int prev2=1,prev1=1;
        for(int i=2;i<=n;i++){
           int curr=prev2+prev1;
           prev2=prev1;
           prev1=curr;
        }
        return prev1;
}

