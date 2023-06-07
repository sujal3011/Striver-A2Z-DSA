#include<bits/stdc++.h>
using namespace std;

//Brute force appraoch
//Time complexity--->O(n square)
//Space complexity--->O(1)


//Hashing
//Better appraoch
//Time complexity--->O(n) + O(nlogn)
//Space complexity--->O(n)

vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        map<int,int>freq;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        vector<int>ans;
        for(auto ele:freq){
            if(ele.second>n/3){
                ans.push_back(ele.first);
            }
        }
        return ans;
}


//Better appraoch
//Single iteration
//Time complexity--->O(nlogn)
//Space complexity--->O(n)
vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        map<int,int>freq;
        vector<int>ans;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
            if(freq[nums[i]]==(n/3+1)){
                ans.push_back(nums[i]);
                if(ans.size()==2) break;
            }
        }
        return ans;
}

int main(){

    return 0;
}