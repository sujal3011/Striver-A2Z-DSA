#include<bits/stdc++.h>
using namespace std;


//Time complexity--->(n^2)
//Space complexity--->(1)
void SelectionSort(vector<int> &arr,int n){

    for(int i=0;i<n-2;i++){
        int mini=i;
        for(int j=i;j<n;j++){
            if(arr[j]<arr[mini]) mini=j;
        }
        swap(arr[mini],arr[i]);
    }
}

void printArray(vector<int>arr,int n){
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){

    vector<int>arr={45,898,12,-5,22};
    int n=5;
    SelectionSort(arr,n);
    printArray(arr,n);



    return 0;
}