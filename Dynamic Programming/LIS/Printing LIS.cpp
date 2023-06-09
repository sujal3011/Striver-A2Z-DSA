#include<bits/stdc++.h>
using namespace std;


//Space optmized Tabulation solution
//Time complexity--->O(N x N)
//Space complexity--->O(N)
//Using the last method for finding LIS
vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        
        vector<int>dp(n,1),hash(n);
        for(int i=0;i<n;i++) hash[i]=i;
        int maxi = 1,lastIdx=0;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(arr[i]>arr[prev] && (dp[prev]+1)>dp[i]){
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                lastIdx=i;
            }
        }
        vector<int>ans;
        ans.push_back(arr[lastIdx]);
        while(hash[lastIdx]!=lastIdx){
            lastIdx = hash[lastIdx];
            ans.push_back(arr[lastIdx]);
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
}