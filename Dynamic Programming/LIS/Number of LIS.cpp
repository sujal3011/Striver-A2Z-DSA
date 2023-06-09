#include<bits/stdc++.h>
using namespace std;

//Application of LIS (using the algorithmic approach)
//Time complexity--->O(N x N) + O(N)
//Space complexity--->O(N*2)
int findNumberOfLIS(vector<int>& arr) {
        int n=arr.size();
        vector<pair<int,int>>dp(n,{1,1});   // here dp[i] will store both the length of the LIS and the cnt of all such LIS
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(arr[i]>arr[prev]){
                    if((dp[prev].first + 1)==dp[i].first) dp[i].second+=dp[prev].second;
                    else if((dp[prev].first + 1)>dp[i].first){
                        dp[i].first=dp[prev].first + 1;
                        dp[i].second=dp[prev].second;
                    }
                }
            }
        }

       int maxi=0,cnt=0;
        for(int i=0;i<n;i++){
            if(dp[i].first>maxi){
                maxi=dp[i].first;
                cnt=dp[i].second;
            }
            else if(dp[i].first==maxi){
                cnt+=dp[i].second;
            }
        }
        return cnt;
}