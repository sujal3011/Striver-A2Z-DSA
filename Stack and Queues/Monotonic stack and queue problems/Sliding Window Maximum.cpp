#include<bits/stdc++.h>
using namespace std;


//Optimal approach
//Explanation-->Striver and Aditya Verma video
//Time complexity---O(n) + O(n)
//Space complexity-->O(k)
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(!dq.empty() && dq.front()==(i-k)) dq.pop_front();  //removing the out of scope elements
            while(!dq.empty() && nums[dq.back()]<nums[i]) dq.pop_back();  //removing the elements which are smaller than the current element

            dq.push_back(i);
            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;

    }

int main(){

    return 0;
}