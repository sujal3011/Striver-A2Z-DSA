#include<bits/stdc++.h>
using namespace std;


//Tabulation solution
//Time complexity--->O(N X M)
//Space complexity--->O(N x M) , dp array
int longestCommonSubstr (string S1, string S2, int n, int m)
{
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(S1[i-1]==S2[j-1]){
                    dp[i][j]= 1 + dp[i-1][j-1];
                    ans=max(ans,dp[i][j]);
                }
                else dp[i][j] = 0;
            }
        }
        return ans;
}


//Space optmized Tabulation solution
//Time complexity--->O(N x M)
//Space complexity--->O(2*M)

int longestCommonSubstr (string S1, string S2, int n, int m)
{
        vector<int>prev(m+1,0),curr(m+1,0);
        
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(S1[i-1]==S2[j-1]){
                    curr[j]= 1 + prev[j-1];
                    ans=max(ans,curr[j]);
                }
                else curr[j] = 0;
            }
            prev=curr;
        }
        return ans;
}