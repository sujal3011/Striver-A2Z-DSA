#include<bits/stdc++.h>
using namespace std;


//Application of LIS (using the algorithmic approach)
//Time complexity--->O(N x N x 2)
//Space complexity--->O(N*2)
int LongestBitonicSequence(vector<int>arr)
	{
	    int n=arr.size();
	    vector<int>dp1(n,1),dp2(n,1);
	    
	    for(int i=0;i<n;i++){
	        for(int prev=0;prev<i;prev++){
	            if(arr[i]>arr[prev] && (1 + dp1[prev])>dp1[i]){
	                dp1[i] = 1 + dp1[prev];
	            }
	        }
	    }
	    
	    for(int i=n-1;i>=0;i--){
	        for(int next=n-1;next>i;next--){
	            if(arr[i]>arr[next] && (1 + dp2[next])>dp2[i]){
	                dp2[i] = 1 + dp2[next];
	            }
	        }
	    }
	    
	    int maxi=1;
	    for(int i=0;i<n;i++){
	        maxi=max(maxi,dp1[i]+dp2[i]-1);
	    }
	    return maxi;
}