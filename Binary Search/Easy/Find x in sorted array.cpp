#include<bits/stdc++.h>
using namespace std;

//Time complexity--->O(logn)
//Space complexity--->O(1)
int search(vector<int>& nums, int target) {
        int start=0,end=nums.size()-1;
        int ans=-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }

        return ans;
}

int main(){

    return 0;
}