 #include<bits/stdc++.h>
using namespace std;
 
//Brute force approach
//Time complexity-->O(2*n)
//Space complexity-->O(1)

//Optimal approach
//Using merge sort
//Time complexity-->O(2*nlogn)
//Space complexity-->O(n)

void merge(vector<int> &arr, int low, int mid, int high)
    {
        vector<int>temp;
        int left=low,right=mid+1;
        while(left<=mid && right<=high){
            
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
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
        
        for(int i=low;i<=high;i++){
            arr[i]=temp[i-low];
        }
    }
   int countPairs(vector<int>&arr,int low,int mid,int high){
	   int right=mid+1;
	   int cnt=0;
	   for(int i=low;i<=mid;i++){
		   while(right<=high && arr[i]>2*arr[right]) right++;
		   cnt+=(right-mid-1);
	   }
	   return cnt;
   }
    int mergeSort(vector<int> &arr, int l, int r)
    {
        if(l>=r) return 0;
        int cnt=0;
        int mid=(l+r)/2;
        cnt+=mergeSort(arr,l,mid);
        cnt+=mergeSort(arr,mid+1,r);
		cnt+=countPairs(arr,l,mid,r);
        merge(arr,l,mid,r);
		return cnt;
    }
int reversePairs(vector<int> &arr, int n){
	return mergeSort(arr,0,n-1);	
}