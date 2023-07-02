#include<bits/stdc++.h>
using namespace std;


//Time complexity--->(n^2)(for average and worst case),O(n)(for best case,when array is already sorted)
//Space complexity--->(1)
void BubbleSort(vector<int> &arr,int n){

   for(int i=n-1;i>=0;i--){
    int didSwap=0;
    for(int j=0;j<i;j++){
        if(arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
            didSwap=1;
        }
    }
    if(didSwap==0) break;   //array is already sorted
   }
}

void printArray(vector<int>arr,int n){
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){

    vector<int>arr={45,898,12,-5,22};
    int n=5;
    BubbleSort(arr,n);
    printArray(arr,n);



    return 0;
}