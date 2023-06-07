#include<bits/stdc++.h>
using namespace std;

//Memoization solution
//Time complexity--->O(N X M)
//Space complexity--->O(N x M) + O(N + M),  dp array and recursive stack space
//Using 0-based indexing

int func(int i,int j,string &s1,string &s2,vector<vector<int>> &dp){

        if(i<0) return j+1;
        if(j<0) return i+1;
        
        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]){
            return func(i-1,j-1,s1,s2,dp);
        }
        int insert =  func(i,j-1,s1,s2,dp);
        int Delete =  func(i-1,j,s1,s2,dp);
        int replace =  func(i-1,j-1,s1,s2,dp);
        return dp[i][j] = 1 + min(insert,min(Delete,replace));  
    }

    int minDistance(string s, string t) {

        int n=s.length(),m=t.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return func(n-1,m-1,s,t,dp);
}


//Memoization solution
//Time complexity--->O(N X M)
//Space complexity--->O(N x M) + O(N + M),  dp array and recursive stack space
//Using 1-based indexing
int func(int i,int j,string &s1,string &s2,vector<vector<int>> &dp){

        if(i==0) return j;
        if(j==0) return i;
        
        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i-1]==s2[j-1]){
            return func(i-1,j-1,s1,s2,dp);
        }
        int insert =  func(i,j-1,s1,s2,dp);
        int Delete =  func(i-1,j,s1,s2,dp);
        int replace =  func(i-1,j-1,s1,s2,dp);
        return dp[i][j] = 1 + min(insert,min(Delete,replace));  
    }

    int minDistance(string s, string t) {

        int n=s.length(),m=t.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return func(n,m,s,t,dp);
}


//Tabulation solution
//Time complexity--->O(N X M)
//Space complexity--->O(N x M) , dp array
//For tabulation to work we need to follow 1-based indexing 

int minDistance(string s, string t) {

        int n=s.length(),m=t.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int j=0;j<=m;j++) dp[0][j]=j; 
        for(int i=0;i<=n;i++) dp[i][0]=i; 

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1];
                else{
                    dp[i][j]=1 + min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                }
            }
        }
        return dp[n][m];
        
}

//Space optmized Tabulation solution
//Time complexity--->O(N x M)
//Space complexity--->O(2*M)

int minDistance(string s, string t) {

        int n=s.length(),m=t.length();
        vector<int>prev(m+1,0),curr(m+1,0);
        for(int j=0;j<=m;j++) prev[j]=j; 
        prev[0]=0; 

        for(int i=1;i<=n;i++){
            curr[0]=i;
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) curr[j]=prev[j-1];
                else{
                    curr[j]=1 + min(prev[j],min(curr[j-1],prev[j-1]));  //This can't be further space optimized because the current state depends on the the previous value of both the previous and the current row.
                }   
            }
            prev=curr;
            
        }
        return prev[m];
        
}

