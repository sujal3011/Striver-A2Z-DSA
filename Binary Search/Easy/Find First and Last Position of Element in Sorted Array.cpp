#include<bits/stdc++.h>
using namespace std;

//Time complexity--->O(logn)
//Space complexity--->O(1)
vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int start=0,end=n-1,fi=-1,ei=-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(nums[mid]>target){
                end=mid-1;
            }
            else if(nums[mid]<target){
                start=mid+1;
            }
            else if(nums[mid]==target){
               
               fi=mid;
               end=mid-1;     
            }
        }

        start=0,end=n-1;

        while(start<=end){
            int mid=(start+end)/2;
            if(nums[mid]>target){
                end=mid-1;
            }
            else if(nums[mid]<target){
                start=mid+1;
            }
            else if(nums[mid]==target){
               
                ei=mid;
                start=mid+1;
     
            }
        }

        vector<int>ans;
        ans.push_back(fi);
        ans.push_back(ei);
        return ans;
    }

int main(){

    return 0;
}