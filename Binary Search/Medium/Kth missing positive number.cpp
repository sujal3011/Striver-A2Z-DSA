#include<bits/stdc++.h>
using namespace std;

//Linear Search
//Time complexity-->O(n)
//Space complexity-->O(1)
int findKthPositive(vector<int>& arr, int k) {

        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]<=k) k++;
            else break;
        }
        return k;
        
}

//Binary Search
//Time complexity-->O(logn)
//Space complexity-->O(1)
int findKthPositive(vector<int>& arr, int k) {

        int n=arr.size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=(low + high)/2;
            int missing = arr[mid] - (mid+1);
            if(k>missing) low = mid + 1;
            else high=mid-1; 
        }

        // missing numbers at high = arr[high] - (high + 1)
        // more required = k - missing numbers at high
        // ans = arr[high] + more required = arr[high] + k - arr[high] + high + 1 = (k + high + 1)

        return k + high + 1;
        // return k + low;
    }