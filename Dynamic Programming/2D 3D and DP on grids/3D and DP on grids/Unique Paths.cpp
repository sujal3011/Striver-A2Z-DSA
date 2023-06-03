#include <bits/stdc++.h> 
using namespace std;


//Memoization solution
//Time complexity--->O(N*M)
//Space complexity--->O((N-1)+(M-1))+O(N*M),recursive stack space and dp array

int func(int i,int j,int m,int n, vector<vector<int>> &dp){

        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int up = func(i-1,j,m,n,dp);
        int left = func(i,j-1,m,n,dp);
        return dp[i][j] = left + up;
}
int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return func(m-1,n-1,m,n,dp);
}

//Tabulation solution
//Time complexity--->O(NxM)
//Space complexity--->O(NxM),for dp array

int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)  dp[i][j]=1;
                else{
                    int left=0,up=0;
                    if((i-1)>=0) up+=dp[i-1][j];
                    if((j-1)>=0) left+=dp[i][j-1];
                    dp[i][j]=left + up;
                }
            }
        }

        return dp[m-1][n-1];
}
//Space optmized Tabulation solution
//Time complexity--->O(NxM)
//Space complexity--->O(N)
 int uniquePaths(int m, int n) {
        vector<int>prev(n,0);
        for(int i=0;i<m;i++){
            vector<int>temp(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0)  temp[j]=1;
                else{
                    int left=0,up=prev[j];
                    if((j-1)>=0) left+=temp[j-1];
                    temp[j]=left + up;
                }
            }
            prev=temp;
        }

        return prev[n-1];
}