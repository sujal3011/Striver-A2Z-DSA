#include <bits/stdc++.h> 
using namespace std;

//Memoization solution
//Time complexity--->O(N X target)
//Space complexity--->O(N)+O(N X target), recursive stack space and dp array

bool func(int i,int target,vector<int> &arr,vector<vector<int>> &dp){
        
        if(target==0) return true;
        if(i==0) return (target==arr[0]);
        
        if(dp[i][target]!=-1) return dp[i][target];
        
        bool notTake=func(i-1,target,arr,dp);
        bool take=false;
        if(target>=arr[i]){
            take=func(i-1,target-arr[i],arr,dp);
        }
        return dp[i][target] = (take || notTake);
} 
bool isSubsetSum(vector<int>arr, int sum){
        
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        
        return func(n-1,sum,arr,dp);
}
//Tabulation solution
//Time complexity--->O(N x target)
//Space complexity--->O(N x target),for dp array

bool isSubsetSum(vector<int>arr, int sum){
        
        int n=arr.size();
        
        vector<vector<bool>>dp(n,vector<bool>(sum+1,false));
        for(int i=0;i<n;i++) dp[i][0]=true;
        if(arr[0]<=sum) dp[0][arr[0]]=true;
        
        for(int i=1;i<n;i++){
            for(int target=1;target<=sum;target++){
                bool notTake=dp[i-1][target];
                bool take = false;
                if(target>=arr[i]) take = dp[i-1][target-arr[i]];
                dp[i][target] = take || notTake;
            }
        }
        return dp[n-1][sum];
        
}
//Space optmized Tabulation solution
//Time complexity--->O(N x target)
//Space complexity--->O(target)
bool isSubsetSum(vector<int>arr, int sum){
        
        int n=arr.size();
        vector<bool>prev(sum+1,0),curr(sum+1,0);
        prev[0]=true;
        if(arr[0]<=sum) prev[arr[0]]=true;
        
        for(int i=1;i<n;i++){
            for(int target=1;target<=sum;target++){
                bool notTake=prev[target];
                bool take = false;
                if(target>=arr[i]) take = prev[target-arr[i]];
                curr[target] = take || notTake;
            }
            prev=curr;
        }
        return prev[sum];
        
}