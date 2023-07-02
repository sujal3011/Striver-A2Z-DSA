#include<bits/stdc++.h>
using namespace std;

//Time complexity-->O(n) * log(max element in the array)
//Space complexity-->O(1)
long long calculateTime(vector<int> &piles,int k){
        long long time=0;
        for(int i=0;i<piles.size();i++) time+=ceil(piles[i]/(double)k);
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int maxi=0;
        int n=piles.size();
        for(int i=0;i<n;i++) maxi=max(maxi,piles[i]);
        long long low=1,high=maxi;

        while(low<=high){
            long long mid=(low + high)/2;
            if(calculateTime(piles,mid)>h) low=mid+1;
            else high=mid-1;
        }

        return low;
}