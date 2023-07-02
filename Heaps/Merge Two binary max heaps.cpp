#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr,int i,int sz){
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;
        if(left<sz && arr[left]>arr[largest]) largest=left;
        if(right<sz && arr[right]>arr[largest]) largest=right;
        
        if(largest!=i){
            swap(arr[i],arr[largest]);
            heapify(arr,largest,sz);
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int>ans;
        for(int i=0;i<n;i++) ans.push_back(a[i]);
        for(int i=0;i<m;i++) ans.push_back(b[i]);
        
        int sz=n+m;
        for(int i=sz/2-1;i>=0;i--){
            heapify(ans,i,sz);
        }
        
        return ans;
        
}