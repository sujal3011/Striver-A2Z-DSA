#include<bits/stdc++.h>
using namespace std;

//Linear Search
//Time complexity-->O(n*(max element - min element)) + O(nlogn) (for sorting)
//Space complexity-->O(1)
 bool isPossible(vector<int>&stalls,int n,int k,int mini){
        
        int cows=k-1,i=1,last=stalls[0];
        while(i<n && cows>0){
            if((stalls[i]-last)>=mini){
                last=stalls[i];
                cows--;
            }
            i++;
        }
        if(cows>0) return false;
        return true;
    }

    int solve(int n, int k, vector<int> &stalls) {
        
        sort(stalls.begin(),stalls.end());
        int mini=stalls[0],maxi=stalls[n-1];
        for(int i=1;i<=maxi-mini;i++){
            if(isPossible(stalls,n,k,i)) continue;
            else return (i-1);
        }
        return -1;
    }

//Binary Search
//Time complexity-->O(n) * O(log(max element - min element)) + O(nlogn)
//Space complexity-->O(1)
bool isPossible(vector<int>&stalls,int n,int k,int mini){
        
        int cows=k-1,i=1,last=stalls[0];
        while(i<n && cows>0){
            if((stalls[i]-last)>=mini){
                last=stalls[i];
                cows--;
            }
            i++;
        }
        if(cows>0) return false;
        return true;
}

int solve(int n, int k, vector<int> &stalls) {
        
        sort(stalls.begin(),stalls.end());
        int mini=stalls[0],maxi=stalls[n-1];
        
        int low=1,high=maxi-mini;
        while(low<=high){
            int mid=(low+high)/2;
            if(isPossible(stalls,n,k,mid)) low=mid+1;
            else high=mid-1;
            
        }
        return high;
        
}