#include<bits/stdc++.h>
using namespace std;

//Brute approach
//Time complexity--->O(n*n)
//Space complexity--->O(1)
int maxLen(vector<int>&A, int n)
    {   
        int len=0;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=A[j];
                if(sum==0){
                   len=max(len,j-i+1);
                }
            }
        }
        return len;
    }


//Optimized approach
//Hashing and prefix sum
//Time complexity--->O(nlogn)/O(n),depending on the hashmap used
//Space complexity--->O(n)
int maxLen(vector<int>&A, int n)
    {   
        int len=0,preSum=0;
        unordered_map<int, int> presum;
        for(int i=0;i<n;i++){
           preSum+=A[i];
           if(preSum==0){
                len=max(len,i+1);
           }
           else if(presum.find(preSum)!=presum.end()){
               len=max(len,i-presum[preSum]);
             
           }
           else{
               presum.insert({preSum,i});
           }
        }
        return len;
    }