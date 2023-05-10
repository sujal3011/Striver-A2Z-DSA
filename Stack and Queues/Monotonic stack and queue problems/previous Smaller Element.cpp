#include<bits/stdc++.h>
using namespace std;

//Considering the array to be non circular
//Time complexity-->O(n)
//Space complexity-->O(n)
vector<int>prevSmaller(vector<int> &A) {
    stack<int>st;
    int n=A.size();
    vector<int>ans(n);
    for(int i=0;i<n;i++){
        while(!st.empty() && st.top()>=A[i]) st.pop();
        if(st.empty()) ans[i]=-1;
        else ans[i]=st.top();
        st.push(A[i]);
    }
    return ans;
}

int main(){

    return 0;
}