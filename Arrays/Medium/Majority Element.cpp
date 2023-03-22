#include<bits/stdc++.h>
using namespace std;


//Using map
//Time complexity--->O(nlogn)
//Space complexoty--->O(n)
 int majorityElement(vector<int>& nums) {
        int n=nums.size();
        map<int ,int>mm;
        for(int i=0;i<n;i++){
            mm[nums[i]]++;
        }

        int ans;

        for(auto it:mm){
            if(it.second>(n/2)){
                ans=it.first;
                break;
            }
        }

        return ans;
    }


//Moore's Voting Algorithm
//Most optimized
//Time complexity--->O(n)
//Space complexoty--->O(1)
int majorityElement(vector<int>& arr) {
        int n=arr.size();
        int cnt=1,element=arr[0];
        for(int i=1;i<n;i++){
            if(cnt==0){
                element=arr[i];
                cnt=1;
            }

            else if(arr[i]==element){
                cnt++;
            }
            else if(arr[i]!=element){
                cnt--;
            }
        }

        return element;


    }


int main(){

    return 0;
}