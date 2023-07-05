#include<bits/stdc++.h>
using namespace std;


void generateCombinations(int idx,int num,vector<vector<int>> &ans,vector<int> &ds,int k,int n){
    
    if(idx>=k){
        ans.push_back(ds);
        return;
    }  
    
    for(int i=num;i<=(n+1+idx-k);i++){
        ds[idx] = i;
        generateCombinations(idx + 1,i + 1,ans,ds,k,n);
    }
}

vector<vector<int> >combine(int n, int k) {
    vector<vector<int>>ans;
    vector<int>ds(k,0); 
    generateCombinations(0,1,ans,ds,k,n);
    return ans;   
}