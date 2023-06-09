#include<bits/stdc++.h>
using namespace std;


//Application of LIS (using the algorithmic approach)
vector<int> largestDivisibleSubset(vector<int>& arr) {

        sort(arr.begin(),arr.end());  //IMPORTANT STEP
        
        int n=arr.size();
        vector<int>dp(n,1),hash(n);
        for(int i=0;i<n;i++) hash[i]=i;
        int maxi = 1,lastIdx=0;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if((arr[i]%arr[prev])==0 && (dp[prev]+1)>dp[i]){  //checking for divisibility
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