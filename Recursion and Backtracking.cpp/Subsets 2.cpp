#include<bits/stdc++.h>
using namespace std;


//Brute solution
//Using set
void generateSubsets(int idx,vector<int>&A,vector<int> &ds,set<vector<int>> &ans){
    
    if(idx==A.size()){
        ans.insert(ds);
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
    set<vector<int>>ans;
    generateSubsets(0,A,ds,ans);
    
    vector<vector<int>>res(ans.begin(),ans.end());
    return res;
}

//Optimal solution
//Without using set
//Using the same logic as sum combination 2
void generateSubsets(int idx,vector<int>&A,vector<int> &ds,vector<vector<int>> &ans){
    
    if(idx>=A.size()){
        ans.push_back(ds);
        return;
    }
    
    for(int i=idx;i<=A.size();i++){
        if(i==A.size()){
            generateSubsets(i+1,A,ds,ans);
            continue;
        } 
        if(i>idx && A[i]==A[i-1]) continue;
        
        ds.push_back(A[i]);
        generateSubsets(i+1,A,ds,ans);
        ds.pop_back();
    }
    
}

vector<vector<int> > subsets(vector<int> &A) {
    
    sort(A.begin(),A.end());
    vector<int>ds;
    vector<vector<int>>ans;
    generateSubsets(0,A,ds,ans);
    sort(ans.begin(),ans.end());
    return ans;
}