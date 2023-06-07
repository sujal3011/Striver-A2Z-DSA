#include<bits/stdc++.h>
using namespace std;

//Memoization solution
//Time complexity--->O(N X M)
//Space complexity--->O(N x M) + O(N + M),  dp array and recursive stack space

int func(int i1,int i2,string &s1,string &s2,vector<vector<int>> &dp){
        if(i1<0 || i2<0) return 0;

        if(dp[i1][i2]!=-1) return dp[i1][i2];

        if(s1[i1]==s2[i2]) return dp[i1][i2] = 1 + func(i1-1,i2-1,s1,s2,dp);
        return dp[i1][i2] = max(func(i1-1,i2,s1,s2,dp),func(i1,i2-1,s1,s2,dp));  
    }
    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.length(),m=s2.length();

        vector<vector<int>>dp(n,vector<int>(m,-1));
        return func(n-1,m-1,s1,s2,dp);

    }

int func(int i1,int i2,string &s1,string &s2,vector<vector<int>> &dp){
        if(i1==0 || i2==0) return 0;  //Shifting of index

        if(dp[i1][i2]!=-1) return dp[i1][i2];

        if(s1[i1-1]==s2[i2-1]) return dp[i1][i2] = 1 + func(i1-1,i2-1,s1,s2,dp);
        return dp[i1][i2] = max(func(i1-1,i2,s1,s2,dp),func(i1,i2-1,s1,s2,dp));  
    }
    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.length(),m=s2.length();

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return func(n,m,s1,s2,dp);

}


//Tabulation solution
//Time complexity--->O(N X M)
//Space complexity--->O(N x M) + dp array

int longestCommonSubsequence(string s1, string s2) {
        int n=s1.length(),m=s2.length();

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1] ;
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            } 
        }
        return dp[n][m];
}

//Space optmized Tabulation solution
//Time complexity--->O(N x M)
//Space complexity--->O(2*M)

int longestCommonSubsequence(string s1, string s2) {
        int n=s1.length(),m=s2.length();

        vector<int>prev(m+1,0),curr(m+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){ 
                if(s1[i-1]==s2[j-1]) curr[j] = 1 + prev[j-1] ;
                else curr[j] = max(prev[j],curr[j-1]);
            }
            prev=curr; 
        }
        return prev[m];
}



