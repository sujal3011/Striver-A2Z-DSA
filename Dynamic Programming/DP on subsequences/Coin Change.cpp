#include <bits/stdc++.h> 
using namespace std;

//Memoization solution
//Time complexity--->O(N X W)
//Space complexity--->O(N)+O(N X W), recursive stack space and dp array

int func(int ind,int amt,vector<int>& coins,vector<vector<int>> &dp){

        if(ind==0){
            if(amt%coins[0]==0) return amt/coins[0];
            return 1e9;
        }
        if(dp[ind][amt]!=-1) return dp[ind][amt];

        int notTake = func(ind-1,amt,coins,dp);
        int take=1e9;
        if(amt>=coins[ind]) take = 1 + func(ind,amt-coins[ind],coins,dp);
        return dp[ind][amt]=min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        if(func(n-1,amount,coins,dp)!=1e9) return func(coins.size()-1,amount,coins,dp);
        return -1;
}

//Tabulation solution
//Time complexity--->O(N x W)
//Space complexity--->O(N x W),for dp array

int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));

        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) dp[0][i] = i/coins[0];
            else dp[0][i] = 1e9;
        }

        for(int i=1;i<n;i++){
            for(int amt=0;amt<=amount;amt++){
                int notTake=dp[i-1][amt];
                int take=1e9;
                if(amt>=coins[i]) take = 1 + dp[i][amt-coins[i]];
                dp[i][amt]=min(take,notTake); 
            }
        }
        if(dp[n-1][amount]==1e9) return -1;
        return dp[n-1][amount];

}
//Space optmized Tabulation solution
//Time complexity--->O(N x W)
//Space complexity--->O(2*W)
int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int>prev(amount+1,0),curr(amount+1,0);

        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) prev[i] = i/coins[0];
            else prev[i] = 1e9;
        }

        for(int i=1;i<n;i++){
            for(int amt=0;amt<=amount;amt++){
                int notTake=prev[amt];
                int take=1e9;
                if(amt>=coins[i]) take = 1 + curr[amt-coins[i]];
                curr[amt]=min(take,notTake); 
            }
            prev=curr;
        }
        if(prev[amount]==1e9) return -1;
        return prev[amount];

}