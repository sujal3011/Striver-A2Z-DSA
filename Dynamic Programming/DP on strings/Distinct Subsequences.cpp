#include<bits/stdc++.h>
using namespace std;

//Memoization solution
//Time complexity--->O(N X M)
//Space complexity--->O(N x M) + O(N + M),  dp array and recursive stack space
//Using 0-based indexing

 int func(int i,int j,string &s,string &t,vector<vector<int>> &dp){

        if(j<0) return 1;
        if(i<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==t[j]){
            return func(i-1,j-1,s,t,dp) + func(i-1,j,s,t,dp);
        }
        return dp[i][j] = func(i-1,j,s,t,dp);
    }
    int numDistinct(string s, string t) {
        int n=s.length(),m=t.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return func(n-1,m-1,s,t,dp);

}


//Memoization solution
//Time complexity--->O(N X M)
//Space complexity--->O(N x M) + O(N + M),  dp array and recursive stack space
//Using 1-based indexing
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
//Space complexity--->O(N x M) , dp array
//For tabulation to work we need to follow 1-based indexing 

int numDistinct(string s, string t) {
        int n=s.length(),m=t.length();
        vector<vector<double>>dp(n+1,vector<double>(m+1,-1));

        for(int i=0;i<=n;i++) dp[i][0] = 1;
        for(int j=1;j<=m;j++) dp[0][j] = 0;  //IMPORTANT----> j will start from 1 instead of 0 so that that value of dp[0][0] doesn't get overwritten


        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){

                if(s[i-1]==t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j]; 
                }
                else dp[i][j] = dp[i-1][j];
            }
        }

        return (int)dp[n][m];


}

//Space optmized Tabulation solution
//Time complexity--->O(N x M)
//Space complexity--->O(2*M)

int numDistinct(string s, string t) {
        int n=s.length(),m=t.length();
        vector<double>prev(m+1,0),curr(m+1,0);

        prev[0] = 1,curr[0]=1;
        for(int j=1;j<=m;j++) prev[j] = 0;


        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){

                if(s[i-1]==t[j-1]){
                    curr[j] = prev[j-1] + prev[j]; 
                }
                else curr[j] = prev[j];
            }
            prev=curr;
        }

        return (int)prev[m];


    }

//Further Space optmized Tabulation solution
//Time complexity--->O(N x M)
//Space complexity--->O(M)

int numDistinct(string s, string t) {
        int n=s.length(),m=t.length();
        vector<double>prev(m+1,0);

        prev[0] = 1;
        for(int j=1;j<=m;j++) prev[j] = 0;


        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){

                if(s[i-1]==t[j-1]){
                    prev[j] = prev[j-1] + prev[j]; 
                }
                //else prev[j] = prev[j];
            }
        }

        return (int)prev[m];


    }


