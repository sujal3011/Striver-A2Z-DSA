#include<bits/stdc++.h>
using namespace std;


//Approach 1
//Time complexity--->O(n! * n)
//Space complexity--->O(n) + O(n) + O(n)
void generatePermutations(vector<int>&A,vector<int>&taken,vector<int>&temp,vector<vector<int>> &ans){
    
    if(temp.size()==A.size()){
        ans.push_back(temp);
        return;
    }
    
    for(int i=0;i<A.size();i++){
        if(!taken[i]){
            temp.push_back(A[i]);
            taken[i]=1;
            generatePermutations(A,taken,temp,ans);
            temp.pop_back();
            taken[i]=0;
        }
    }
}

vector<vector<int> >permute(vector<int> &A) {
    
    int n=A.size();
    vector<int>temp;
    vector<int>taken(n,0);
    vector<vector<int>>ans;
    generatePermutations(A,taken,temp,ans);
    return ans;
    
}


//Optimized approach
//Time complexity--->O(n! * n)
//Space complexity--->O(n) ,only for recursive stack space,not using temp array or taken array
void generatePermutations(int idx,vector<int>&A,vector<vector<int>> &ans){
    
    if(idx==A.size()){
        ans.push_back(A);
        return;
    }
    
    for(int i=idx;i<A.size();i++){
        swap(A[idx],A[i]);
        generatePermutations(idx+1,A,ans);
        swap(A[idx],A[i]);
    }
}

vector<vector<int> >permute(vector<int> &A) {
    
    int n=A.size();
    vector<vector<int>>ans;
    generatePermutations(0,A,ans);
    return ans;
    
}
