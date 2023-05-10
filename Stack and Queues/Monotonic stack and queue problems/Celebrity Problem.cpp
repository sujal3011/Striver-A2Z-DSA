#include<bits/stdc++.h>
using namespace std;

//Brute force
//Time complexity---O(n^2)
//Space complexity-->O(1)

int celebrity(vector<vector<int> >& M, int n) 
    {
        for(int i=0;i<n;i++) {
            bool flag=1;
            for(int j=0;j<n;j++){
                if(j!=i && M[j][i]!=1){
                    flag=0;
                    break;
                }
            }
            if(flag) for(int j=0;j<n;j++){
                if(M[i][j]==1){
                    flag=0;
                    break;
                }
            }
            if(flag) return i;     
        }    
        return -1;
}

//Optimal approach
//Time complexity---O(n)
//Space complexity-->O(n)
int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int>st;
        for(int i=0;i<n;i++){
            st.push(i);
        }
        while(st.size()>1){
            int x=st.top();
            st.pop();
            int y=st.top();
            st.pop();
            if(M[x][y]==0){
                //y can't be a celebrity
                st.push(x);
            }
            else{
                //x can't be a celebrity
                st.push(y);
            }
        }
        int p=st.top();
        st.pop();
        
        //checking for p (only potential candidate)
        bool flag=1;
        for(int j=0;j<n;j++){
            if(j!=p && M[j][p]!=1){
                    flag=0;
                    break;
                }
            }
            if(flag) for(int j=0;j<n;j++){
                if(M[p][j]==1){
                    flag=0;
                    break;
                }
            }
            if(flag) return p;
            return -1;
    }

int main(){

    return 0;
}