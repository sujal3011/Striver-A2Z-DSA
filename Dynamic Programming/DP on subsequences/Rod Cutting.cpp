#include <bits/stdc++.h> 
using namespace std;

//Memoization solution
//Time complexity--->O(N X W)
//Space complexity--->O(N)+O(N X W), recursive stack space and dp array

int func(int i,int target,int price[],vector<vector<int>> &dp){
        
        if(target==0) return 0;
        if(i==0){
            return price[0]*target;
        }
        
        if(dp[i][target]!=-1) return dp[i][target];
        
        int notTake = func(i-1,target,price,dp);
        int take=0;
        if((i+1)<=target) take = price[i] + func(i,target-(i+1),price,dp);
        return dp[i][target] = max(take,notTake);
}
int cutRod(int price[], int n) {
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return func(n-1,n,price,dp);
}

//Tabulation solution
//Time complexity--->O(N x W)
//Space complexity--->O(N x W),for dp array

int cutRod(int price[], int n) {
        
        int target=n;
        vector<vector<int>>dp(n,vector<int>(target+1,0));
        for(int i=0;i<=target;i++){
            dp[0][i]=price[0]*i;
        }
        for(int i=1;i<n;i++){
            for(int tar=1;tar<=target;tar++){
                int notTake=dp[i-1][tar];
                int take=0;
                if((i+1)<=tar) take = price[i] + dp[i][tar-i-1];
                dp[i][tar]=max(take,notTake);
            }
        }
        return dp[n-1][target];
}

//Space optmized Tabulation solution
//Time complexity--->O(N x W)
//Space complexity--->O(2*W)
int cutRod(int price[], int n) {
        
        int target=n;
        vector<int>prev(target+1,0),curr(target+1,0);
        for(int i=0;i<=target;i++){
            prev[i]=price[0]*i;
        }
        for(int i=1;i<n;i++){
            for(int tar=1;tar<=target;tar++){
                int notTake=prev[tar];
                int take=0;
                if((i+1)<=tar) take = price[i] + curr[tar-i-1];
                curr[tar]=max(take,notTake);
            }
            prev=curr;
        }
        return prev[target];
}

//Further Space optmized Tabulation solution
//Time complexity--->O(N x W)
//Space complexity--->O(W)
int cutRod(int price[], int n) {
        
        int target=n;
        vector<int>prev(target+1,0);
        for(int i=0;i<=target;i++){
            prev[i]=price[0]*i;
        }
        for(int i=1;i<n;i++){
            for(int tar=1;tar<=target;tar++){
                int notTake=prev[tar];
                int take=0;
                if((i+1)<=tar) take = price[i] + prev[tar-i-1];
                prev[tar]=max(take,notTake);
            }
        }
        return prev[target];
}