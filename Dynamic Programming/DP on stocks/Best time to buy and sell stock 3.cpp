#include<bits/stdc++.h>
using namespace std;

//Memoization solution
//Time complexity--->O(N X 5)
//Space complexity--->O(N x 5) + O(N),  dp array and recursive stack space
int func(int i,int buy,vector<int> &prices,int n,vector<vector<int>> &dp){

        if(i==n) return 0;

        if(dp[i][buy+2]!=-1) return dp[i][buy+2];

        if(buy>=0 && buy<2){
            return dp[i][buy+2] = max( -prices[i] + func(i+1,-(buy+1),prices,n,dp) , func(i+1,buy,prices,n,dp) );
        }
        else if(buy<0){
           return dp[i][buy+2] = max( prices[i] + func(i+1,-buy,prices,n,dp) , func(i+1,buy,prices,n,dp) );
        }
        else return dp[i][buy+2] = 0;
}
int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(5,-1));
        return func(0,0,prices,n,dp);
}


//Tabulation solution
//Time complexity--->O(N X 5)
//Space complexity--->O(N x 5) , dp array

int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(5,0));
        for(int i=0;i<5;i++) dp[n][i] = 0;

        for(int i=n-1;i>=0;i--){
            for(int buy=-2;buy<=2;buy++){

                if(buy>=0 && buy<2){
                     dp[i][buy+2] = max( -prices[i] + dp[i+1][-(buy+1)+2] , dp[i+1][buy+2]);
                }
                else if(buy<0){
                     dp[i][buy+2] = max( prices[i] + dp[i+1][-buy+2] , dp[i+1][buy+2] );
                }
                else  dp[i][buy+2] = 0;

            }
        }

        return dp[0][2];
}

//Space optmized Tabulation solution
//Time complexity--->O(N x 5)
//Space complexity--->O(5)

int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>ahead(5,0),curr(5,0);
        for(int i=0;i<5;i++) ahead[i] = 0;

        for(int i=n-1;i>=0;i--){
            for(int buy=-2;buy<=2;buy++){

                if(buy>=0 && buy<2){
                     curr[buy+2] = max( -prices[i] + ahead[-(buy+1)+2] , ahead[buy+2]);
                }
                else if(buy<0){
                     curr[buy+2] = max( prices[i] + ahead[-buy+2] , ahead[buy+2] );
                }
                else  curr[buy+2] = 0;

            }
            ahead=curr;
        }

        return ahead[2];
}