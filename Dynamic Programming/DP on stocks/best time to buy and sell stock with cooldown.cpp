#include<bits/stdc++.h>
using namespace std;

//Memoization solution
//Time complexity--->O(N X 3)
//Space complexity--->O(N x 3) + O(N),  dp array and recursive stack space
int func(int i,int buy,vector<int> &prices,int n,vector<vector<int>> &dp){

        if(i==n) return 0;

        if(dp[i][buy]!=-1) return dp[i][buy];

        if(buy==0)  return dp[i][buy] = max( prices[i] + func(i+1,2,prices,n,dp),func(i+1,0,prices,n,dp));
        else if(buy==1){
            return dp[i][buy] = max( -prices[i] + func(i+1,0,prices,n,dp),func(i+1,1,prices,n,dp) );
        }
        else  return dp[i][buy] = func(i+1,1,prices,n,dp);
}
int maxProfit(vector<int>& prices) {
         int n=prices.size();
         vector<vector<int>>dp(n,vector<int>(3,-1));
         return func(0,1,prices,n,dp);
}

//Tabulation solution
//Time complexity--->O(N X 3)
//Space complexity--->O(N x 3) , dp array

 int maxProfit(vector<int>& prices) {
         int n=prices.size();
         vector<vector<int>>dp(n+1,vector<int>(3,0));
         for(int i=0;i<3;i++) dp[n][i] = 0;

         for(int i=n-1;i>=0;i--){
             for(int buy=0;buy<3;buy++){

                if(buy==0)  dp[i][buy] = max( prices[i] + dp[i+1][2],dp[i+1][0]);
                else if(buy==1){
                    dp[i][buy] = max( -prices[i] + dp[i+1][0],dp[i+1][1] );
                }
                else dp[i][buy] = dp[i+1][1];
             }
         }
         return dp[0][1];
}

//Space optmized Tabulation solution
//Time complexity--->O(N x 3)
//Space complexity--->O(3)

int maxProfit(vector<int>& prices) {

         int n=prices.size();
         vector<int>ahead(3,0),curr(3,0);
         for(int i=0;i<3;i++) ahead[i] = 0;

         for(int i=n-1;i>=0;i--){
             for(int buy=0;buy<3;buy++){

                if(buy==0)  curr[buy] = max( prices[i] + ahead[2],ahead[0]);
                else if(buy==1){
                    curr[buy] = max( -prices[i] + ahead[0],ahead[1] );
                }
                else curr[buy] = ahead[1];
             }
             ahead=curr;
         }
         return ahead[1];
}