#include<bits/stdc++.h>
using namespace std;

//Brute force approach
//Sorting
//Time complexity--->O(nlogn)
//Space complexity--->O(1)

//Optimized approach
//Using priority queue
///Time complexity--->O(nlogk)
//Space complexity--->O(1)
int kthSmallest(int arr[], int l, int r, int k) {
        priority_queue<int>pq;
        for(int i=0;i<k;i++){
            pq.push(arr[i]);
        }
        
        for(int i=k;i<=r;i++){
            if(arr[i]<pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        
        return pq.top();
    }
