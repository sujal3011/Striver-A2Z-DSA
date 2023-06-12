 #include<bits/stdc++.h>
using namespace std;
 
//Brute force approach
//Time complexity-->O(2*n)
//Space complexity-->O(1)

//Optimal approach
//Using merge sort
//Time complexity-->O(nlogn)
//Space complexity-->O(n)

long long merge(long long *arr, long long low, long long mid, long long high)
    {
        vector<int>temp;
        long long cnt=0;
        long long left=low,right=mid+1;
        while(left<=mid && right<=high){
            
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                cnt+=(mid-left+1);
                temp.push_back(arr[right]);
                right++;
            }
        }
        
        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        
        while(right<=high){
            temp.push_back(arr[right]);
            right++;
        }
        
        for(long long i=low;i<=high;i++){
            arr[i]=temp[i-low];
        }
        return cnt;
    }
    long long mergeSort(long long *arr, long long l, long long r)
    {
        if(l>=r) return 0;
        long long cnt=0;
        
        long long mid=(l+r)/2;
        cnt+=mergeSort(arr,l,mid);
        cnt+=mergeSort(arr,mid+1,r);
        cnt+=merge(arr,l,mid,r);
        return cnt;
    }
    

long long getInversions(long long *arr, int n){
    return mergeSort(arr,0,n-1);
}