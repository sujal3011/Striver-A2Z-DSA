#include<bits/stdc++.h>
using namespace std;

//Brute force
//Time complexity--->O(n^2)
//Space complexoty--->O(1)
//Checking all pairs
        

//Better appraoch        
//Time complexity--->O(nlogn) + O(n)
//Space complexoty--->O(n)
//Using sorting 

int maximumGap(const vector<int> &A) {
    
    int n=A.size();
    vector<pair<int,int>>vec;
    int min_index=INT_MAX,ans=0;
    for(int i=0;i<n;i++){
        vec.push_back({A[i],i});
    }
    sort(vec.begin(),vec.end());
    for(int i=0;i<n;i++){
        min_index=min(min_index,vec[i].second);
        ans=max(ans,vec[i].second-min_index);
    }
    return ans;
}

//Time complexity--->O(n)
//Space complexoty--->O(1)
//Most optimized approach
