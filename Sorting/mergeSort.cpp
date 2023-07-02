#include<bits/stdc++.h>
using namespace std;


//Time complexity--->(nlogn)
//Space complexity--->(n)

void merge(vector<int> &arr,int low,int mid,int high){

    int left=low,right=mid+1;
    vector<int>temp;
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

    while (right<=high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
    

}
void mergeSort(vector<int> &arr,int low,int high){

    if(low>=high) return;

    int mid=(low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);

  
}

void printArray(vector<int>arr,int n){
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){

    vector<int>arr={45,898,12,-5,22};
    int n=5;
    mergeSort(arr,0,n-1);
    printArray(arr,n);



    return 0;
}