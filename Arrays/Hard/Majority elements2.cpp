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


//Optimized appraoch
//Time complexity--->O(n)
//Space complexity--->O(1)

int repeatedNumber(const vector<int> &A) {
    int n=A.size();
    int cnt1=0,cnt2=0;
    int ele1=-1,ele2=-1;
    for(int i=0;i<n;i++){
        if(cnt1==0 && ele2!=A[i]){
            cnt1=1;
            ele1=A[i];
        }
        else if(cnt2==0 && ele1!=A[i]){
            cnt2=1;
            ele2=A[i];
        }
        else if(ele1==A[i]) cnt1++;
        else if(ele2==A[i]) cnt2++;
        else{
            cnt1--;
            cnt2--;
        }
    }
    
    cnt1=0,cnt2=0;
    for(int i=0;i<n;i++){
        if(A[i]==ele1) cnt1++;
        else if(A[i]==ele2) cnt2++;
    }
    
    if(cnt1>n/3) return ele1;
    if(cnt2>n/3) return ele2;
    return -1;
}


int main(){

    return 0;
}