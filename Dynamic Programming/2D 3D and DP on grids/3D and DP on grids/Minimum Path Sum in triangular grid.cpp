#include <bits/stdc++.h> 
using namespace std;


//Memoization solution
//Time complexity--->O(N*N)
//Space complexity--->O(N)+O(NXN), recursive stack space and dp array

int func(int i,int j,int m,vector<vector<int>>& triangle,vector<vector<int>> &dp){
        if(i==m-1) return triangle[i][j];

        if(dp[i][j]!=-1) return dp[i][j];

        int left=func(i+1,j,m,triangle,dp);
        int right=func(i+1,j+1,m,triangle,dp);
        return dp[i][j]=min(left,right)+triangle[i][j];
}
int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<vector<int>>dp(m,vector<int>(m,-1));
        return func(0,0,m,triangle,dp);
}

//Tabulation solution
//Time complexity--->O(NxN)
//Space complexity--->O(NxN),for dp array

 int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<vector<int>>dp(m,vector<int>(m,0));

        for(int i=m-1;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                if(i==m-1) dp[i][j]=triangle[i][j];
                else{
                    int left=dp[i+1][j];
                    int right=dp[i+1][j+1];
                    dp[i][j]=min(left,right)+triangle[i][j];
                }
            }
        }
        return dp[0][0];
}
//Space optmized Tabulation solution
//Time complexity--->O(NxN)
//Space complexity--->O(N)
int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<int>next(m);
        for(int i=0;i<m;i++){
            next[i]=triangle[m-1][i];
        }
        for(int i=m-2;i>=0;i--){
            vector<int>curr(m);
            for(int j=0;j<triangle[i].size();j++){

                int left=next[j];
                int right=next[j+1];
                curr[j]=min(left,right)+triangle[i][j];
            }
            next=curr;
        }
        return next[0];
}