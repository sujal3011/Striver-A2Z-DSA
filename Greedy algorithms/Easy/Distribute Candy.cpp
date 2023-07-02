#include<bits/stdc++.h>
using namespace std;

//Brute force
//Time complexity-->O(n^2)
//Space complexity-->O(1)

//Better
//Time complexity-->O(3*n)
//Space complexity-->O(2*n)
int candy(vector<int> &A) {
    
    int n=A.size();
    vector<int>leftToRight(n,1),rightToLeft(n,1);
    
    for(int i=1;i<n;i++){
        if(A[i]>A[i-1]){
            leftToRight[i]=max(leftToRight[i],leftToRight[i-1]+1);
        }
    }
    
    for(int i=n-2;i>=0;i--){
        if(A[i]>A[i+1]){
            rightToLeft[i]=max(rightToLeft[i],rightToLeft[i+1]+1);
        }
    }
    
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=max(leftToRight[i],rightToLeft[i]);
    }
    
    return ans;
}


//Optimal
//Time complexity-->O(3*n)
//Space complexity-->O(n)
int candy(vector<int> &A) {
    
    int n=A.size();
    vector<int>candies(n,1);
    
    for(int i=1;i<n;i++){
        if(A[i]>A[i-1]){
            candies[i]=max(candies[i],candies[i-1]+1);
        }
    }
    
    for(int i=n-2;i>=0;i--){
        if(A[i]>A[i+1]){
            candies[i]=max(candies[i],candies[i+1]+1);
        }
    }
    
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=candies[i];
    }
    
    return ans;
}