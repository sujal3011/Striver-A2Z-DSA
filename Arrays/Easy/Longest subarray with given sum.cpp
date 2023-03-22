#include<bits/stdc++.h>
using namespace std;


//This is the most optimized solution if the array containes only positive,0,and negatives
//Hashing
//Time complexity--->O(nlogn)
//Space complexity--->O(n)

int lenOfLongSubarr(int A[],  int n, int k) 
{
        map<int,int>mm;
        int sum=0,length=0;
        for(int i=0;i<n;i++){
            sum+=A[i];
            if(sum==k){
                length=max(length,i+1);
            }
            
            auto it=mm.find(sum-k);
                if(it!=mm.end()){
                    length=max(length,i-mm[sum-k]);
                }
            
           if(!mm[sum]){
               mm[sum]=i;
           }
        }
        
        return length;
} 




//This is the most optimized solution if the array containes only positive elements and zero
//Sliding window
//Time complexity--->O(2*n)
//Space complexity--->O(1)

int lenOfLongSubarr(int arr[],  int n, int k) 
{ 
        int start=0,end=0;
        int sum=arr[0],maxLen=0;
        while(end<n){
            if(start<=end && sum>k){
                sum-=arr[start];
                start++;
            }
            else if(sum==k){
                maxLen=max(maxLen,end-start+1);
            }
            
            start++;
            if(end<n) sum+=arr[start];
            
        }
        
        return maxLen;
}


int main(){

    return 0;
}