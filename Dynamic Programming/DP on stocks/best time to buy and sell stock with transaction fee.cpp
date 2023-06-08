#include<bits/stdc++.h>
using namespace std;

//Memoization solution
//Time complexity--->O(N X 2)
//Space complexity--->O(N x 2) + O(N),  dp array and recursive stack space
int func(int i,int buy,vector<int>& prices,int n,int fee,vector<vector<int>> &dp){
       
        if(i==n) return 0;

        if(dp[i][buy]!=-1) return dp[i][buy];


        if(buy) return dp[i][buy] = max( (-prices[i] + func(i+1,0,prices,n,fee,dp)),func(i+1,1,prices,n,fee,dp));
        else return dp[i][buy] = max( (prices[i] - fee + func(i+1,1,prices,n,fee,dp)), func(i+1,0,prices,n,fee,dp));
        
    }
    int maxProfit(vector<int>& prices,int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return func(0,1,prices,n,fee,dp);
    }


//Tabulation solution
//Time complexity--->O(N X 2)
//Space complexity--->O(N x 2) , dp array

int maxProfit(vector<int>& prices,int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        dp[n][0] = dp[n][1] = 0;

        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                if(buy)  dp[i][buy] = max( -prices[i] + dp[i+1][0],dp[i+1][1]);
                else  dp[i][buy] = max( prices[i] - fee + dp[i+1][1], dp[i+1][0]);
            }
        }
        return dp[0][1];
}

 

//Space optmized Tabulation solution
//Time complexity--->O(N x 2)
//Space complexity--->O(1)

 int maxProfit(vector<int>& prices,int fee) {
        int n=prices.size();
        vector<int>next(2,0),curr(2,0);
        next[0] = next[1] = 0;

        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                if(buy)  curr[buy] = max( -prices[i] + next[0],next[1]);
                else  curr[buy] = max( prices[i] - fee + next[1], next[0]);
            }
            next=curr;
        }
        return next[1];
}

//Space optmized Tabulation solution
//Time complexity--->O(N x 2)
//Space complexity--->O(1)
//Using 4 variables
int maxProfit(vector<int>& prices,int fee) {
        int n=prices.size();
        int currBuy,currNotBuy,aheadNotBuy,aheadBuy;
        aheadNotBuy = aheadBuy = 0;

        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                currBuy = max( -prices[i] + aheadNotBuy,aheadBuy);
                currNotBuy = max( prices[i] - fee + aheadBuy, aheadNotBuy);
            }
            aheadBuy = currBuy;
            aheadNotBuy = currNotBuy;
        }
        return aheadBuy;
    }
