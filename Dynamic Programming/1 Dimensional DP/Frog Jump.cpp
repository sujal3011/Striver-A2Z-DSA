#include <bits/stdc++.h> 
using namespace std;


//Memoization solution
//Time complexity--->O(N)
//Space complexity--->O(N)+O(N),recursive stack space and dp array
int frogHelp(int i,int n,vector<int> &heights,vector<int> &dp){

    if(i==n) return 0;
    if(i==n-1) return abs(heights[n-1]-heights[n-2]);

    if(dp[i]!=-1) return dp[i];

    int left=frogHelp(i+1,n,heights,dp);
    int right=frogHelp(i+2,n,heights,dp);
    return dp[i]=min(left+abs(heights[i-1]-heights[i]),right+abs(heights[i-1]-heights[i+1]));
}
int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n+1,-1);
   return frogHelp(1,n,heights,dp);
   
}


//Tabulation solution
//Time complexity--->O(N)
//Space complexity--->O(N),for dp array

int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n+1,0);
    dp[n]=0;
    dp[n-1]=abs(heights[n-1]-heights[n-2]);
    for(int i=n-2;i>=1;i--){
        int left=dp[i+1];
        int right=dp[i+2];
        dp[i]=min(left+abs(heights[i-1]-heights[i]),right+abs(heights[i-1]-heights[i+1]));
    } 
   return dp[1];
}


//Space optmized Tabulation solution
//Time complexity--->O(N)
//Space complexity--->O(1)
int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n+1,0);
    int x=0;
    int y=abs(heights[n-1]-heights[n-2]);
    for(int i=n-2;i>=1;i--){
        int curr=min(y+abs(heights[i-1]-heights[i]),x+abs(heights[i-1]-heights[i+1]));
        x=y;
        y=curr;

    } 
   return y;
}