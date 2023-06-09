#include<bits/stdc++.h>
using namespace std;

//Memoization solution
//Time complexity--->O(N X N)
//Space complexity--->O(N x N) + O(N),  dp array and recursive stack space
int func(int i,int prevIdx,vector<int> &nums,int n,vector<vector<int>> &dp){

        if(i==n+1) return 0;

        if(dp[i][prevIdx]!=-1) return dp[i][prevIdx];

        int len = func(i+1,prevIdx,nums,n,dp);
        if(prevIdx==0 || nums[i-1]>nums[prevIdx-1]) len = max(len,1 + func(i+1,i,nums,n,dp));
        return dp[i][prevIdx] = len; 
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n,-1));
        return func(1,0,nums,n,dp);
}

//Tabulation solution
//Time complexity--->O(N X N)
//Space complexity--->O(N x N) , dp array
 int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        for(int i=n-1;i>=0;i--){
            for(int prevIdx=i-1;prevIdx>=-1;prevIdx--){
                int len = dp[i+1][prevIdx+1];
                if(prevIdx==-1 || nums[i]>nums[prevIdx]) len = max(len,1 + dp[i+1][i+1]);
                dp[i][prevIdx+1] = len; 
            }
        }
        return dp[0][0];
        
    }
 

//Space optmized Tabulation solution
//Time complexity--->O(N x N)
//Space complexity--->O(N x 2)

 int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>next(n+1,0),curr(n+1,0);

        for(int i=n-1;i>=0;i--){
            for(int prevIdx=i-1;prevIdx>=-1;prevIdx--){
                int len = next[prevIdx+1];
                if(prevIdx==-1 || nums[i]>nums[prevIdx]) len = max(len,1 + next[i+1]);
                curr[prevIdx+1] = len; 
            }
            next=curr;
        }
        return next[0];
        
}

//Algorithmic approach
//Time complexity--->O(N x N)
//Space complexity--->O(N)
int lengthOfLIS(vector<int>& arr) {
        int n=arr.size();
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(arr[i]>arr[prev]){
                    dp[i]=max(dp[i],1+dp[prev]);
                }
            }

        }

        int maxi = 1;
        for(int i=0;i<n;i++){
            maxi=max(maxi,dp[i]);
        }
        return maxi;
        
}


