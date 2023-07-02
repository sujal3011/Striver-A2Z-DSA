#include<bits/stdc++.h>
using namespace std;


//Time complexity--->(n^2)(for average and worst case),O(n)(for best case,when array is already sorted)
//Space complexity--->(1)
void InsertionSort(vector<int> &arr,int n){

   for(int i=0;i<n;i++){
    int j=i;
    while(j>0 && arr[j-1]>arr[j]){
        swap(arr[j],arr[j-1]);
        j--;
    }
   }
}

void printArray(vector<int>arr,int n){
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){

    vector<int>arr={45,898,12,-5,22};
    int n=5;
    InsertionSort(arr,n);
    printArray(arr,n);



    return 0;
}