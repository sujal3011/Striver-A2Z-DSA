#include <bits/stdc++.h> 
using namespace std;


//Memoization solution
//Time complexity--->O(NxN)
//Space complexity--->O(N)+O(NXN), recursive stack space and dp array

int func(int i,int j,int n,vector<vector<int>>& matrix,vector<vector<int>> &dp){
        if(j<0 || j==n) return INT_MAX; 
        if(i==0) return matrix[i][j];

        if(dp[i][j]!=-1) return dp[i][j];

        int top=func(i-1,j,n,matrix,dp);
        int left=func(i-1,j-1,n,matrix,dp);
        int right=func(i-1,j+1,n,matrix,dp);
        return dp[i][j] = min(min(top,left),right) + matrix[i][j];

}
int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int ans=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++) ans=min(ans,func(n-1,i,n,matrix,dp));
        return ans;
        
}
//Tabulation solution
//Time complexity--->O(NxN)
//Space complexity--->O(NxN),for dp array

int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==0) dp[i][j]=matrix[i][j];
                else{
                    int left=1e9,right=1e9;
                    int top=dp[i-1][j];
                    if((j-1)>=0) left=dp[i-1][j-1];
                    if((j+1)<n) right=dp[i-1][j+1];
                    dp[i][j]=min(top,min(left,right))+matrix[i][j];

                }
            }  
        }
        int ans=1e9;
        for(int i=0;i<n;i++) ans=min(ans,dp[n-1][i]);
        return ans;  
}
//Space optmized Tabulation solution
//Time complexity--->O(NxN)
//Space complexity--->O(N)
int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int>prev(n);
        for(int i=0;i<n;i++){
            prev[i]=matrix[0][i];
        }
        for(int i=1;i<n;i++){
            vector<int>temp(n);
            for(int j=0;j<n;j++){
            
                int left=1e9,right=1e9;
                int top=prev[j];
                if((j-1)>=0) left=prev[j-1];
                if((j+1)<n) right=prev[j+1];
                temp[j]=min(top,min(left,right))+matrix[i][j]; 
            }  
            prev=temp;
        }
        int ans=1e9;
        for(int i=0;i<n;i++) ans=min(ans,prev[i]);
        return ans;
        
}