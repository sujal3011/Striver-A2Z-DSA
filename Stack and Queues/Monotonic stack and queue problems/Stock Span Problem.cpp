#include<bits/stdc++.h>
using namespace std;

//Optimal solution
//Previous greater element
//Time complexity---O(n)
//Space complexity-->O(n)
vector <int> calculateSpan(int A[], int n)
    {
        vector<int>pge(n);
        vector<int>ans(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && A[st.top()]<=A[i]) st.pop();
            if(st.empty()) pge[i]=-1;
            else pge[i]=st.top();
            st.push(i);
        }
        for(int i=0;i<n;i++){
            if(pge[i]==-1){
                ans[i]=i+1;
            }
            else ans[i]=i-pge[i];
        }
        return ans;
}

int main(){

    return 0;
}