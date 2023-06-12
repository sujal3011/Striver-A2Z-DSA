#include<bits/stdc++.h>
using namespace std;

//Brute approach
//Time complexity--->O(n*n)
//Space complexity--->O(1)

//Optimized approach
//Hashing and prefix xor
//Time complexity--->O(nlogn)/O(n),depending on the hashmap used
//Space complexity--->O(n)
int subsetXOR(vector<int> arr, int n, int k) {
       
       map<int,int>mm;
       int xr=0,cnt=0;
       mm[0]=1;
       for(int i=0;i<n;i++){
           xr=xr^arr[i];
           cnt+=mm[xr^k];
           mm[xr]++;
       }
       return cnt;
}