#include<bits/stdc++.h>
using namespace std;

//Approach 1
//Time complexity--->O(N)
//Space complexity--->O(2*N)
//Using two different minArr and maxArr



//Most optimized
//Time complexity--->O(2*N)
//Space complexity--->O(1)

vector<int> subUnsort(vector<int> &A) {
    
    int n=A.size();
    int mini=INT_MAX,startIdx=-1;
    int maxi=INT_MIN,endIdx=-1;
    
    for(int i=n-1;i>=0;i--){
        if(A[i]<=mini){
            mini=A[i];
            if(startIdx==-1) startIdx=i;
        }
        else{
            startIdx=-1;
        }
    }
    
    for(int i=0;i<n;i++){
        if(A[i]>=maxi){
            maxi=A[i];
            if(endIdx==-1) endIdx=i;
        }
        else{
            endIdx=-1;
        }
    }

    
    if(startIdx==-1 && endIdx==-1) return {0,n-1};  //need to sort the whole array 
    if(startIdx==-1) return {0,endIdx-1};  // reqiured subarray's end point is the end index
    if(endIdx==-1) return {startIdx+1,n-1};  // reqiured subarray's start point is the start index
    if(endIdx < startIdx) return {-1}; // already sorted
    return {startIdx+1,endIdx-1};
}
