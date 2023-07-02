#include<bits/stdc++.h>
using namespace std;

//Linear Search
//Time complexity-->O(n*(total sum - max element+1)) 
//Space complexity-->O(1)
int findMax(int A[],int N){
        int maxi=0;
        for(int i=0;i<N;i++) maxi=max(maxi,A[i]);
        return maxi;
    }
    
    long long findSum(int A[],int N){
        long long sum=0;
        for(int i=0;i<N;i++) sum+=A[i];
        return sum;
    }
    
    
    int countStudents(int A[],int pages,int N){
        
        int students=0,pageCount=0;
        for(int i=0;i<N;i++){
            if(pageCount + A[i]<=pages){
                pageCount+=A[i];
            }
            else{
                students++;
                pageCount=A[i];
            }
        }
        students++;
        return students;
    }
    
    int findPages(int A[], int N, int M) 
    {
        if(M>N) return -1;
        long long maxi=findMax(A,N);
        long long sum=findSum(A,N);
        
        for(long long i=maxi;i<=sum;i++){
            if(countStudents(A,i,N)<=M) return i;
        }
        
        return -1;
}

//Binary Search
//Time complexity-->O(n) * O(log(total sum - max element+1))
//Space complexity-->O(1)
int findMax(int A[],int N){
        int maxi=0;
        for(int i=0;i<N;i++) maxi=max(maxi,A[i]);
        return maxi;
    }
    
    long long findSum(int A[],int N){
        long long sum=0;
        for(int i=0;i<N;i++) sum+=A[i];
        return sum;
    }
    
    
    int countStudents(int A[],int pages,int N){
        
        int students=0,pageCount=0;
        for(int i=0;i<N;i++){
            if(pageCount + A[i]<=pages){
                pageCount+=A[i];
            }
            else{
                students++;
                pageCount=A[i];
            }
        }
        students++;
        return students;
    }
    
    int findPages(int A[], int N, int M) 
    {
        if(M>N) return -1;
        long long maxi=findMax(A,N);
        long long sum=findSum(A,N);
        
        long long low=maxi,high=sum;
        while(low<=high){
            long long mid=(low+high)/2;
            if(countStudents(A,mid,N)>M) low=mid+1;
            else high=mid-1;
        }
        
        return low;
}