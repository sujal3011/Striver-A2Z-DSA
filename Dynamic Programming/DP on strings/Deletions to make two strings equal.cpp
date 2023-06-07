#include<bits/stdc++.h>
using namespace std;


//Application of longest common subsequence 
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

int minDistance(string word1, string word2) {
        int n=word1.length(),m=word2.length();
        int lcs=longestCommonSubsequence(word1,word2);
        return n+m-2*lcs;
}