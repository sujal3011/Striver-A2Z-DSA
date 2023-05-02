#include<bits/stdc++.h>
using namespace std;

//Time complexity--->O(nlogn)
//Space complexity--->O(1)
pair<int, int> getFloorAndCeil(int v[], int n, int x) {
    
    sort(v,v+n);
    
    int start=0,end=n-1,floor=-1,ceil=-1;
    while(start<=end){
            int mid=(start+end)/2;
            
            if((v[mid]==x) || (v[mid]<x && (mid+1)>=n) || (v[mid]<x && v[mid+1]>x) ){
                floor=mid;
                break;
            }
            else if(v[mid]<x){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
    }
    
    
    pair<int,int>ans;
    if(floor==-1){
        ans={-1,v[0]};
        return ans;
    }
    else if(v[floor]==x) ceil=floor;
    else if(floor==n-1){
        ans={v[floor],-1};
        return ans;
    }
    else ceil=floor+1;
    ans={v[floor],v[ceil]};
    return ans;
     
}



//Time complexity--->O(n)
//Space complexity--->O(1)
pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    int floor=INT_MIN,ceil=INT_MAX;
    for(int i=0;i<n;i++){
        
        if(arr[i]==x){
            floor=x;
            ceil=x;
            break;
        }
        
        
        if(arr[i]<=x && arr[i]>=floor){
            floor=arr[i];
            
        }
        else if(arr[i]>=x && arr[i]<=ceil){
            ceil=arr[i];
        }
    }
    pair<int,int>ans;
    if(floor==INT_MIN){
        ans={-1,ceil};
    }
    else if(ceil==INT_MAX){
        ans={floor,-1};
    }
    
    else{
        ans={floor,ceil};
    }
    
    return ans;
}

int main(){

    return 0;
}