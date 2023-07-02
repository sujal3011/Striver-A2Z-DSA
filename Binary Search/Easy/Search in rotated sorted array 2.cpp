#include<bits/stdc++.h>
using namespace std;

//Time complexity--->O(logn)(average), O(n/2) in worst case
//Space complexity--->O(1)
 bool search(vector<int>& nums, int target) {
        
        int n=nums.size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=(low + high)/2;
            if(nums[mid]==target) return true;
            if(nums[mid]==nums[low] && nums[mid]==nums[high]){
                low++;
                high--;
                continue;
            } 
            else if(nums[low]<=nums[mid]){
                if(target>=nums[low] && target<=nums[mid]) high=mid-1;
                else low=mid+1;
            }
            else if(target>=nums[mid+1] && target<=nums[high]) low=mid+1;
            else high=mid-1;
        }

        return false;
}