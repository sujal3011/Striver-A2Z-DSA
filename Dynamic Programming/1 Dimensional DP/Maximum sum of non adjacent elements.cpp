#include <bits/stdc++.h> 
using namespace std;


//Memoization solution
//Time complexity--->O(N)
//Space complexity--->O(N)+O(N),recursive stack space and dp array
int func(int n,int *arr,int i,vector<int> &dp){
	    
	    if(i==0) return arr[0];
	    if(i<0) return 0;
	    if(dp[i]!=-1) return dp[i];
	  
	    int Pick=func(n,arr,i-2,dp)+arr[i];
	    int nonPick=func(n,arr,i-1,dp);
	    return dp[i]=max(Pick,nonPick);
}
int findMaxSum(int *arr, int n) {
	    
	    vector<int>dp(n,-1);
	    return func(n,arr,n-1,dp);
}

//Tabulation solution
//Time complexity--->O(N)
//Space complexity--->O(N),for dp array

int findMaxSum(int *arr, int n) {
	    
	    vector<int>dp(n,0);
	    dp[0]=arr[0];
	    for(int i=1;i<n;i++){
	        int pick=arr[i];
	        if(i>=2) pick+=dp[i-2];
	        int notpick=dp[i-1];
	        dp[i]=max(pick,notpick);
	    }
	    return dp[n-1];
}
//Space optmized Tabulation solution
//Time complexity--->O(N)
//Space complexity--->O(1)
int findMaxSum(int *arr, int n) {
	    
	    int x=0,y=arr[0];
	    for(int i=1;i<n;i++){
	        int curr=max(arr[i]+x,y);
	        x=y;
	        y=curr;
	    }
	    return y;
}