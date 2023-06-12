#include<bits/stdc++.h>
using namespace std;

//Brute approach
//Time complexity--->O(n*n)
//Space complexity--->O(1)

//Optimized approach
//Hashing and prefix sum
//Time complexity--->O(nlogn)/O(n),depending on the hashmap used
//Space complexity--->O(n)
int subarraySum(vector<int>& arr, int k) {
        int n=arr.size(); 
       map<int,int>preCount;
       int preSum=0,cnt=0;
       preCount[0]=1;
       for(int i=0;i<n;i++){
           preSum+=arr[i];
          cnt+=preCount[preSum-k];
           preCount[preSum]++;
       }
       return cnt;

}