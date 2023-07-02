#include<bits/stdc++.h>
using namespace std;

//Time complexity-->O(n) * log(max element - min element +1)
//Space complexity-->O(1)
 int findMin(vector<int>&arr,int n){
        int mini=INT_MAX;
        for(int i=0;i<n;i++) mini=min(mini,arr[i]);
        return mini;
    }


    int findMax(vector<int>&arr,int n){
        int maxi=INT_MIN;
        for(int i=0;i<n;i++) maxi=max(maxi,arr[i]);
        return maxi;
    }

    int countBouquets(vector<int> &bloomDay,int n,int day,int k){
        int cnt=0,i=0,ans=0;
        while(i<n){
            if(day>=bloomDay[i]) cnt++;
            else{
                ans+=cnt/k;
                cnt=0;
            }
            i++;    
        }
        ans+=cnt/k;
        return ans;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n=bloomDay.size();
        long long req=m;
        req=req*k;
        if(n<req) return -1;
        int mini=findMin(bloomDay,n);
        int maxi=findMax(bloomDay,n);

        int low=mini,high=maxi;

        while(low<=high){
            int mid=(low + high)/2;
            if(countBouquets(bloomDay,n,mid,k)<m) low=mid+1;
            else high=mid-1; 
        }

        return low;
}