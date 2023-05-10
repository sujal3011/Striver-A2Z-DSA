#include<bits/stdc++.h>
using namespace std;

//Optimal solution
//Using stack
//Time complexity---O(n)
//Space complexity-->O(n)

vector<int> asteroidCollision(vector<int>& A) {
        int n=A.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            bool flag=1;
            while(!st.empty() && flag && A[i]<0 && st.top()>0){
                int diff=A[i]+st.top();
                if(diff<0){
                    st.pop();
                }
                else if(diff>0){
                    flag=0;
                }
                else{
                    flag=0;
                    st.pop();
                }
            } 
            if(flag) st.push(A[i]);
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

}

int main(){

    return 0;
}