#include <bits/stdc++.h> 
using namespace std;

//Memoization solution
//Time complexity--->O(N X W)
//Space complexity--->O(N)+O(N X W), recursive stack space and dp array

int func(int i,int w,int wt[],int val[],vector<vector<int>> &dp){
        
        if(wt<=0) return 0;
        if(i==0){
            if(w>=wt[0]) return val[0]*(w/wt[0]);
            else return 0;
        }
        if(dp[i][w]!=-1) return dp[i][w];
        
        int notTake = func(i-1,w,wt,val,dp);
        int take=0;
        if(w>=wt[i]) take = func(i,w-wt[i],wt,val,dp) + val[i];
        return dp[i][w] = max(take,notTake);
}
int knapSack(int N, int W, int val[], int wt[])
{ 
        vector<vector<int>>dp(N,vector<int>(W+1,-1));
       return func(N-1,W,wt,val,dp);
}

//Tabulation solution
//Time complexity--->O(N x W)
//Space complexity--->O(N x W),for dp array

int knapSack(int n, int W, int val[], int wt[])
    { 
         vector<vector<int>>dp(n,vector<int>(W+1,0));
        
        for(int i=0;i<=W;i++){
            if(i>=wt[0]) dp[0][i]=val[0]*(i/wt[0]);
        }
        for(int i=1;i<n;i++){
            for(int weight=1;weight<=W;weight++){
                int notTake=dp[i-1][weight];
                int take=0;
                if(weight>=wt[i]) take=dp[i][weight-wt[i]] + val[i];
                dp[i][weight]=max(take,notTake);
            }
        }
        
        
       return dp[n-1][W];
    }

//Space optmized Tabulation solution
//Time complexity--->O(N x W)
//Space complexity--->O(2*W)
int knapSack(int n, int W, int val[], int wt[])
    { 
         vector<int>prev(W+1,0),curr(W+1,0);
        
        for(int i=0;i<=W;i++){
            if(i>=wt[0]) prev[i]=val[0]*(i/wt[0]);
        }
        for(int i=1;i<n;i++){
            for(int weight=1;weight<=W;weight++){
                int notTake=prev[weight];
                int take=0;
                if(weight>=wt[i]) take=curr[weight-wt[i]] + val[i];
                curr[weight]=max(take,notTake);
            }
            prev=curr;
        }
        
        
       return prev[W];
}


//Further Space optmized Tabulation solution
//Time complexity--->O(N x W)
//Space complexity--->O(W)
int knapSack(int n, int W, int val[], int wt[])
    { 
         vector<int>prev(W+1,0);
        
        for(int i=0;i<=W;i++){
            if(i>=wt[0]) prev[i]=val[0]*(i/wt[0]);
        }
        for(int i=1;i<n;i++){
            for(int weight=1;weight<=W;weight++){
                int notTake=prev[weight];
                int take=0;
                if(weight>=wt[i]) take=prev[weight-wt[i]] + val[i];
                prev[weight]=max(take,notTake);
            }
        }
        
        
       return prev[W];
}