#include <bits/stdc++.h> 
using namespace std;


//Memoization solution
//Time complexity--->O(N*M)
//Space complexity--->O((N-1)+(M-1))+O(N*M),recursive stack space and dp array

int func(int i,int j,vector<vector<int>>& grid,vector<vector<int>> &dp){

        if(i<0 || j<0) return -1;
        if(i==0 && j==0) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];

        int up=func(i-1,j,grid,dp);
        int left=func(i,j-1,grid,dp);
        int curr=grid[i][j];
        if(up==-1) curr+=left;
        else if(left==-1) curr+=up;
        else curr+= min(up,left);
        return dp[i][j]=curr;
}
int minPathSum(vector<vector<int>>& grid) {

        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return func(m-1,n-1,grid,dp);
}

//Tabulation solution
//Time complexity--->O(NxM)
//Space complexity--->O(NxM),for dp array

int minPathSum(vector<vector<int>>& grid) {

        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(i==0 && j==0) dp[i][j]=grid[i][j];
                else{
                    dp[i][j]=grid[i][j];
                    if((i-1)<0) dp[i][j]+=dp[i][j-1];
                    else if((j-1)<0) dp[i][j]+=dp[i-1][j];
                    else dp[i][j]+=min(dp[i][j-1],dp[i-1][j]);
                }
                
            }
        }

        return dp[m-1][n-1];
       
}
//Space optmized Tabulation solution
//Time complexity--->O(NxM)
//Space complexity--->O(N)
int minPathSum(vector<vector<int>>& grid) {

        int m=grid.size(),n=grid[0].size();
        vector<int>prev(n,0);

        for(int i=0;i<m;i++){
            vector<int>curr(n,0);
            for(int j=0;j<n;j++){

                if(i==0 && j==0) curr[j]=grid[i][j];
                else{
                    curr[j]=grid[i][j];
                    if((i-1)<0) curr[j]+=curr[j-1];
                    else if((j-1)<0) curr[j]+=prev[j];
                    else curr[j]+=min(prev[j],curr[j-1]);
                }   
            }
            prev=curr;
        }

        return prev[n-1];
       
}