#include<bits/stdc++.h>
using namespace std;

//Memoization solution
//Time complexity--->O(N X k)
//Space complexity--->O(N x k) + O(N),  dp array and recursive stack space
int func(int i,int buy,vector<int> &prices,int n,int k,vector<vector<int>> &dp){

        if(i==n) return 0;

        if(dp[i][buy+k]!=-1) return dp[i][buy+k];

        if(buy>=0 && buy<k){
            return dp[i][buy+k] = max( -prices[i] + func(i+1,-(buy+1),prices,n,k,dp) , func(i+1,buy,prices,n,k,dp) );
        }
        else if(buy<0){
           return dp[i][buy+k] = max( prices[i] + func(i+1,-buy,prices,n,k,dp) , func(i+1,buy,prices,n,k,dp) );
        }
        else return dp[i][buy+k] = 0;
}
int maxProfit(int k,vector<int>& prices) {
            int n=prices.size();
            vector<vector<int>>dp(n,vector<int>(2*k+1,-1));
            return func(0,0,prices,n,k,dp);
}


//Tabulation solution
//Time complexity--->O(N X k)
//Space complexity--->O(N x k) , dp array

int maxProfit(int k,vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2*k+1,0));
        for(int i=0;i<k;i++) dp[n][i] = 0;

        for(int i=n-1;i>=0;i--){
            for(int buy=-k;buy<=k;buy++){

                if(buy>=0 && buy<k){
                     dp[i][buy+k] = max( -prices[i] + dp[i+1][-(buy+1)+k] , dp[i+1][buy+k]);
                }
                else if(buy<0){
                     dp[i][buy+k] = max( prices[i] + dp[i+1][-buy+k] , dp[i+1][buy+k] );
                }
                else  dp[i][buy+k] = 0;

            }
        }

        return dp[0][k];
}

//Space optmized Tabulation solution
//Time complexity--->O(N x k)
//Space complexity--->O(k)

 int maxProfit(int k,vector<int>& prices) {
        int n=prices.size();
        vector<int>ahead(2*k+1,0),curr(2*k+1,0);
        for(int i=0;i<k;i++) ahead[i] = 0;

        for(int i=n-1;i>=0;i--){
            for(int buy=-k;buy<=k;buy++){

                if(buy>=0 && buy<k){
                     curr[buy+k] = max( -prices[i] + ahead[-(buy+1)+k] , ahead[buy+k]);
                }
                else if(buy<0){
                     curr[buy+k] = max( prices[i] + ahead[-buy+k] , ahead[buy+k] );
                }
                else  curr[buy+k] = 0;

            }
            ahead=curr;
        }

        return ahead[k];
}