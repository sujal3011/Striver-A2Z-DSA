#include<bits/stdc++.h>
using namespace std;


//Tabulation solution
//Time complexity--->O(N X M)
//Space complexity--->O(N x M) + dp array

string longestCommonSubsequence(string s1, string s2) {
        int n=s1.length(),m=s2.length();

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1] ;
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            } 
        }

        //Time complexity for backtracking--->O(n+m)
        string ans="";
        int len=dp[n][m];  //this is the length of the longest common subsequence
        for(int i=0;i<len;i++) ans+='$';
        int index=len-1;

        int i=n,j=m;
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                ans[index]=s1[i-1];
                index--;
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }
            else j--;
        }

        cout<<ans<<endl;

        
}
