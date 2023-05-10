#include<bits/stdc++.h>
using namespace std;

//Brute force approach
//Considering all the subarrays
//Time complexity--->O(n^3)...optimizing a little makes the time complexity as O(n^2)
//Space complexity--->O(1)


//Optimal solution
//Approach 1
//Using stack (previous and next smaller element)
//Time complexity---O(n)
//Space complexity-->O(n)
vector<int>prevSmaller(vector<int> &A) {
    stack<int>st;
    int n=A.size();
    vector<int>ans(n);
    for(int i=0;i<n;i++){
        while(!st.empty() && A[st.top()]>A[i]) st.pop(); //handling duplicates (A[st.top()>A[i]]) (NOTE: not >=)
        if(st.empty()) ans[i]=-1;
        else ans[i]=st.top();
        st.push(i);
    }
    return ans;
}

vector<int>nextSmaller(vector<int> &A) {
    stack<int>st;
    int n=A.size();
    vector<int>ans(n);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && A[st.top()]>=A[i]) st.pop();
        if(st.empty()) ans[i]=-1;
        else ans[i]=st.top();
        st.push(i);
    }
    return ans;
}

    int sumSubarrayMins(vector<int>& arr) {
        const int M=1e9+7;
        int n=arr.size();
        vector<int>pse=prevSmaller(arr);
        vector<int>nse=nextSmaller(arr);
        int ans=0;
        for(int i=0;i<n;i++){
            int ps=pse[i],ns=nse[i];
            int n1= (ps==-1) ? i:i-ps-1;
            int n2= (ns==-1) ? n-i-1:ns-i-1;  
            ans+=(arr[i]*(n1+1)*(n2+1));
            ans%=M;
        }

        return ans;
}


//Optimal solution
//Approach 2
//Using stack (previous and next smaller element)
//Time complexity---O(n)
//Space complexity-->O(n)
int sumSubarrayMins(vector<int>& A) {
        stack<int>s1,s2;
        int n=A.size();
        vector<int>next_smaller(n),pre_smaller(n);
        for(int i=0;i<n;i++){
            next_smaller[i]=n-i-1;
            pre_smaller[i]=i;
        }
        for(int i=0;i<n;i++){
            while(!s1.empty() && A[s1.top()]>A[i]){
                next_smaller[s1.top()]=i-s1.top()-1;
                s1.pop();
            }
            s1.push(i);
        }
        for(int i=n-1;i>=0;i--){
            while(!s2.empty() && A[s2.top()]>=A[i]){
                pre_smaller[s2.top()]=s2.top()-i-1;
                s2.pop();
            }
            s2.push(i);
        }

        int ans=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            ans+=(A[i]*(pre_smaller[i]+1)*(next_smaller[i]+1));
            ans%=mod;
        }
        return ans;
}

int main(){

    return 0;
}