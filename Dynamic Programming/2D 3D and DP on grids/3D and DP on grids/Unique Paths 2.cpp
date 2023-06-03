#include <bits/stdc++.h> 
using namespace std;

//Tabulation solution
//Time complexity--->O(NxM)
//Space complexity--->O(NxM),for dp array

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]) continue;
                else if(i==0 && j==0) dp[i][j]=1;
                else{
                    int left=0,up=0;
                    if((i-1)>=0) up+=dp[i-1][j];
                    if((j-1)>=0) left+=dp[i][j-1];
                    dp[i][j]=left+up;

                }
            }
        }
        return dp[m-1][n-1];
}

//Space optmized Tabulation solution
//Time complexity--->O(NxM)
//Space complexity--->O(N)
 int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m=obstacleGrid.size(),n=obstacleGrid[0].size();

        vector<int>prev(n,0);
        for(int i=0;i<m;i++){
            vector<int>temp(n,0);
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]) continue;
                if(i==0 && j==0)  temp[j]=1;
                else{
                    int left=0,up=0;
                    if((i-1)>=0) up+=prev[j];
                    if((j-1)>=0) left+=temp[j-1];
                    temp[j]=left + up;
                }
            }
            prev=temp;
        }

        return prev[n-1];
}