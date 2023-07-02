#include<bits/stdc++.h>
using namespace std;

//Time complexity-->O(n) * log(sum of all elements - max element + 1)
//Space complexity-->O(1)
int findMax(vector<int>&arr,int n){
        int maxi=INT_MIN;
        for(int i=0;i<n;i++) maxi=max(maxi,arr[i]);
        return maxi;
    }

    int findSum(vector<int>&arr,int n){
        int sum=0;
        for(int i=0;i<n;i++) sum+=arr[i];
        return sum;
    }

    int findDays(vector<int> &weights,int n,int capacity){

        int i=0,curr=0,days=0;
        while(i<n){
            if(curr+weights[i]<=capacity) curr+=weights[i];
            else{
                days++;
                curr=weights[i];
            }
            i++;
        }
        days++;
        return days;
    }


    int shipWithinDays(vector<int>& weights, int days) {

        int n=weights.size();
        int maxi=findMax(weights,n);
        int sum=findSum(weights,n);
        int low=maxi,high=sum;
        while(low<=high){
            int mid=(low + high)/2;
            if(findDays(weights,n,mid)>days) low=mid+1;
            else high=mid-1;
        }
        return low;
        
}