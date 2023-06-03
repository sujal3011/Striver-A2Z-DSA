#include <bits/stdc++.h> 
using namespace std;

//Aplication of the problem of count subsets with given sum k
//Space optmized Tabulation solution
//Time complexity--->O(N x totalSum)
//Space complexity--->O(totalSum)
const int M=1e9+7;
class Solution {
  public:
    int findWays(vector<int> &arr, int tar)
    {
        int n=arr.size();
        vector<int>prev(tar+1,0),curr(tar+1,0);
        prev[0]=1,curr[0]=1;
        if(arr[0]<=tar) prev[arr[0]]=1;
    
        for(int i=0;i<n;i++){
            for(int target=0;target<=tar;target++){
    
                
            if(i==0){
                if(target==0 && arr[0]==0) curr[target]=2;
                else if(target==0 || target==arr[0]) curr[target]=1;
                else curr[target]=0;
            }
            else{
    
                int notTake=prev[target];
                int take=0;
                if(target>=arr[i]) take=prev[target-arr[i]];
                curr[target]=(take+notTake)%M;
            }
    
            }
            prev=curr;
        }
        return prev[tar];
}

    int countPartitions(int n, int d, vector<int>& arr) {
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        if((sum-d)<0 || ((sum-d)&1)) return 0;
        int target=(sum-d)/2;
        return findWays(arr,target);
    }
};