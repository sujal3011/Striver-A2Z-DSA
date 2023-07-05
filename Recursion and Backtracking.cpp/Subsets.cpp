#include<bits/stdc++.h>
using namespace std;

void generateSubsets(int idx,vector<int>&A,vector<int> &ds,vector<vector<int>> &ans){
    
    if(idx==A.size()){
        ans.push_back(ds);
        return;
    }
    
    ds.push_back(A[idx]);
    generateSubsets(idx+1,A,ds,ans);
    ds.pop_back();
    
    generateSubsets(idx+1,A,ds,ans);
}

vector<vector<int> > subsets(vector<int> &A) {
    
    sort(A.begin(),A.end());
    vector<int>ds;
    vector<vector<int>>ans;
    generateSubsets(0,A,ds,ans);
    sort(ans.begin(),ans.end());
    
    return ans;
}