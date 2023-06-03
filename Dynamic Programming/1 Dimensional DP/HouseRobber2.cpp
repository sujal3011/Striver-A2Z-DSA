#include <bits/stdc++.h> 
using namespace std;

int FindMaxSum(vector<int> &arr, int n)
{
        int prev2=0,prev1=arr[0];
        for(int i=1;i<n;i++){
           int curr=max(prev2+arr[i],prev1);
           prev2=prev1;
           prev1=curr;
        }
        return prev1;
}

//Space optmized Tabulation solution
//Time complexity--->O(N)
//Space complexity--->O(2*N),for computing the two different arrays
int rob(vector<int>& arr) {
        int n=arr.size();
        vector<int> temp1,temp2;
        if(n==1){
            temp1.push_back(arr[0]); 
            temp2.push_back(arr[0]); 
        }
        for(int i=0;i<n-1;i++){
            temp1.push_back(arr[i]); 
        }
        for(int i=1;i<n;i++){
            temp2.push_back(arr[i]); 
        }
        return max(FindMaxSum(temp1,n-1),FindMaxSum(temp2,n-1));
}