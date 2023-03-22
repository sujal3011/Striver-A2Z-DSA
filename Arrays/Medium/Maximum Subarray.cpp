#include<bits/stdc++.h>
using namespace std;


//Time complexity--->O(n^2)
//Space complexoty--->O(1)
int maxSubArray(vector<int>& arr) {
        int n=arr.size();

        int max_sum=INT_MIN;
        for(int i=0;i<n;i++){
            int curr_sum=0;
            for(int j=i;j<n;j++){
                curr_sum+=arr[j];
                if(curr_sum>max_sum){
                    max_sum=curr_sum;
                }
            }
        }
        return max_sum;
}


//Kadane's Algorithm
//Most optimized
//Time complexity--->O(n)
//Space complexity--->O(1)
 int maxSubArray(vector<int>& nums) {
        int sum=0,max_sum=INT_MIN;
        int n=nums.size();

        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum>max_sum){
                max_sum=sum;
            }
            if(sum<0){
                sum=0;
            }
        }

        return max_sum;
    }


int main(){

    return 0;
}