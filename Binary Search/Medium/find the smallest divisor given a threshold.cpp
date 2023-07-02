#include<bits/stdc++.h>
using namespace std;

//Time complexity-->O(n) * log(max element)
//Space complexity-->O(1)
int findMax(vector<int>&arr,int n){
        int maxi=INT_MIN;
        for(int i=0;i<n;i++) maxi=max(maxi,arr[i]);
        return maxi;
    }

    int findDivisionSum(vector<int> &nums,int n,int divisor){
        int sum=0;
        for(int i=0;i<n;i++) sum+=ceil(nums[i]/(double)divisor);
        return sum;    
    }

    int smallestDivisor(vector<int>& nums, int threshold) {

        int n=nums.size();
        if(threshold<n) return -1;
        int maxi=findMax(nums,n);
        int low=1,high=maxi;
        while(low<=high){
            int mid=(low + high)/2;
            if(findDivisionSum(nums,n,mid)>threshold) low=mid+1;
            else high=mid-1;

        }

        return low;
}