#include <bits/stdc++.h> 
using namespace std;

//Memoization solution
//Time complexity--->O(N X W)
//Space complexity--->O(N)+O(N X W), recursive stack space and dp array

int func(int i,int target,vector<int>& coins,vector<vector<int>> &dp){

        if(i==0){
            if(target%coins[0]==0) return 1;
            return 0;
        }

        if(dp[i][target]!=-1) return dp[i][target];

        int notTake = func(i-1,target,coins,dp);
        int take=0;
        if(target>=coins[i]) take=func(i,target-coins[i],coins,dp);
        return dp[i][target] = notTake + take;
     }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return func(n-1,amount,coins,dp);
}

//Tabulation solution
//Time complexity--->O(N x W)
//Space complexity--->O(N x W),for dp array

int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) dp[0][i] = 1;
        }
        for(int i=1;i<n;i++){
            for(int amt=0;amt<=amount;amt++){
                int notTake=dp[i-1][amt];
                int take=0;
                if(amt>=coins[i]) take = dp[i][amt-coins[i]];
                dp[i][amt]=take + notTake;
            }
        }
        return dp[n-1][amount];
        
}
//Space optmized Tabulation solution
//Time complexity--->O(N x W)
//Space complexity--->O(2*W)
int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<int>prev(amount+1,0),curr(amount+1,0);
        
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) prev[i] = 1;
        }
        for(int i=1;i<n;i++){
            for(int amt=0;amt<=amount;amt++){
                int notTake=prev[amt];
                int take=0;
                if(amt>=coins[i]) take = curr[amt-coins[i]];
                curr[amt]=take + notTake;
            }
            prev=curr;
        }
        return prev[amount];
        
}