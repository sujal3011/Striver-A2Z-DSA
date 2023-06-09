#include<bits/stdc++.h>
using namespace std;

bool cmp(const string &s1, const string &s2) {
        return s1.length() < s2.length();
}

bool compareStrings(string &s1,string &s2){  //This function checks whether the strings differ only by a single character or not
    int n = s1.length(),m = s2.length();
    if(n!=(m+1)) return false;
    int i=0,j=0,cnt=0;
    while(i<n){
        if(j>=m || s1[i]!=s2[j]){
            cnt++;
            i++;
        }
        else{
            i++;
            j++;
        }
    }
    if(cnt==1) return true;
    return false;
}

//Application of LIS (using the algorithmic approach)
//Time complexity--->O(NlogN) + O(N x N x L)
//Space complexity--->O(N)
int longestChain(int n, vector<string>& words) {
        
        sort(words.begin(), words.end(), cmp);  //Sorting the vector of words according to the length of the words

        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(compareStrings(words[i],words[prev]) && (dp[prev]+1)>dp[i]){
                    dp[i]=1 + dp[prev];
                }
            }
        }

        int maxi=1;
        for(int i=0;i<n;i++){
            maxi=max(maxi,dp[i]);
        }
        return maxi;
}