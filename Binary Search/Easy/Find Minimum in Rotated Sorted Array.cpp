#include<bits/stdc++.h>
using namespace std;

//Time complexity--->O(logn)
//Space complexity--->O(1)
int findMin(vector<int>& nums) {

        int n=nums.size();
        int low=0,high=n-1,mini=INT_MAX;
        while(low<=high){
            int mid=(low + high)/2;
            if(nums[low]<=nums[mid]){
                mini=min(mini,nums[low]);
                low=mid+1;
            }
            else{
                mini=min(mini,nums[mid]);
                high=mid-1;
            }
        }

        return mini;
        
}