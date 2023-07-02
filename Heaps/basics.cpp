#include<bits/stdc++.h>
using namespace std;

//Following 0-based indexing
//Left child--->2*i+1
//Right child--->2*i+2
//Parent--->i/2

class Heap{

    public:
    vector<int>arr;
    int size;

    Heap(){
        size=0;
    }
    void insert(int val){

        arr.push_back(val);
        size++;
        int index=size-1;
        while(index>0){
            int parent=index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
            }
            else return ;
        }
    }

    void deleteFromHeap(){

        if(size==0){
            cout<<"Nothing to delete"<<endl;
            return;
        }

        arr[0]=arr[size-1];
        size--;

        int idx=0;
        while(idx<size){
            int left_idx=2*idx+1;
            int right_idx=2*idx+2;

            if(left_idx<size && arr[idx]<arr[left_idx]){
                swap(arr[idx],arr[left_idx]);
                idx=left_idx;
            }
            else if(right_idx<size && arr[idx]<arr[right_idx]){
                swap(arr[idx],arr[right_idx]);
                idx=right_idx;
            }
            else{
                return;
            }
        }
    }

    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

void heapify(vector<int> &arr,int size,int i){

    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<size && arr[largest]<arr[left]){
        largest=left;
    }
    if(right<size && arr[largest]<arr[right]){
        largest=right;
    }

    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,size,largest);
    }
}

int main(){

    // Heap hp;
    // hp.insert(55);
    // hp.insert(54);
    // hp.insert(53);
    // hp.insert(50);
    // hp.insert(52);

    // hp.print();

    // hp.deleteFromHeap();
    // hp.print();


    vector<int>arr={54,53,55,52,50};
    int n=arr.size();
    for(int i=n/2-1;i>=0;i--){  //nodes from (n/2)th to (n-1)th after leaf nodes
        heapify(arr,n,i);
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;



    return 0;
}