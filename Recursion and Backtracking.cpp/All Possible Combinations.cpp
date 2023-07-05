#include <bits/stdc++.h>
using namespace std;


void solveSpecialStrings(int idx,int n,vector<string> &A,string &ds,vector<string> &ans){
    
    if(idx==n){
        ans.push_back(ds);
        return;
    }
    
    string temp = A[idx];
    for(int i=0;i<temp.size();i++){
        ds[idx] = temp[i];
        solveSpecialStrings(idx + 1,n,A,ds,ans);
    }
}
vector<string> specialStrings(vector<string> &A) {
    
    vector<string>ans;
    int n=A.size();
    string ds(n,'.');
    solveSpecialStrings(0,n,A,ds,ans);
    return ans;
}
