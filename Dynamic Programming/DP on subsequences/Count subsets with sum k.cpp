#include <bits/stdc++.h> 
using namespace std;

//Memoization solution
//Time complexity--->O(N X target)
//Space complexity--->O(N)+O(N X target), recursive stack space and dp array


int func(int i,int target,vector<int> &arr,vector<vector<int>> &dp){
    if(i==0){
        if(target==0 && arr[0]==0) return 2;
        if(target==0 || target==arr[0]) return 1;
        return 0;
    }

    if(dp[i][target]!=-1) return dp[i][target];

    int notTake=func(i-1,target,arr,dp);
    int take=0;
    if(target>=arr[i]) take+=func(i-1,target-arr[i],arr,dp);
    return dp[i][target]=take+notTake;
}
int findWays(vector<int> &num, int tar)
{
    int n=num.size();
    vector<vector<int>>dp(n,vector<int>(tar+1,-1));
    return func(n-1,tar,num,dp);
}


//Tabulation solution
//Time complexity--->O(N x target)
//Space complexity--->O(N x target),for dp array

int findWays(vector<int> &arr, int tar)
{
    int n=arr.size();
    vector<vector<int>>dp(n,vector<int>(tar+1,0));

    for(int i=0;i<n;i++){
        for(int target=0;target<=tar;target++){

        if(i==0){
            if(target==0 && arr[0]==0) dp[0][target]=2;
            else if(target==0 || target==arr[0]) dp[0][target]=1;
            else dp[0][target]=0;
        }
        else{

            int notTake=dp[i-1][target];
            int take=0;
            if(target>=arr[i]) take=dp[i-1][target-arr[i]];
            dp[i][target]=take+notTake;
        }

        }
    }
    return dp[n-1][tar];
}
//Space optmized Tabulation solution
//Time complexity--->O(N x target)
//Space complexity--->O(target)
int findWays(vector<int> &arr, int tar)
{
    int n=arr.size();
    vector<int>prev(tar+1,0),curr(tar+1,0);
    prev[0]=1,curr[0]=1;
    if(arr[0]<=tar) prev[arr[0]]=1;

    for(int i=0;i<n;i++){
        for(int target=0;target<=tar;target++){

            
        if(i==0){
            if(target==0 && arr[0]==0) curr[target]=2;
            else if(target==0 || target==arr[0]) curr[target]=1;
            else curr[target]=0;
        }
        else{

            int notTake=prev[target];
            int take=0;
            if(target>=arr[i]) take=prev[target-arr[i]];
            curr[target]=take+notTake;
        }

        }
        prev=curr;
    }
    return prev[tar];
}