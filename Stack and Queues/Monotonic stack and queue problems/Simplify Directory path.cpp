#include <bits/stdc++.h>
using namespace std;


//Leetcode solution
string simplifyPath(string path) {

        stack<string>st;
        int n=path.size();
        string curr="";
        for(int i=0;i<n;i++){

            if(path[i]=='/'){

                if(curr==".."){
                    if(st.size()>=2){
                        st.pop();
                        st.pop();
                    }
                }
                else if(curr!="" && curr!=".") st.push(curr);
                curr="";
                if(st.empty() || st.top()!="/") st.push("/");
            }
            else curr+=path[i];
        }
        if(curr==".." && st.size()>=2){
            st.pop();
            st.pop();
        } 
        if(curr!="" && curr!="." && curr!="..") st.push(curr);
        if(st.size() > 1 && st.top()=="/") st.pop();

        string ans="";
        while(!st.empty()){
           ans = st.top() + ans;
            st.pop();
        }

        return ans;

        
}

//Interviewbit solution
string simplifyPath(string A) {
    
    int n=A.size();
    stack<char>st;
    string ans="";
    for(int i=0;i<n;i++){
        if(A[i]=='/'){
            if(st.empty() || st.top()!='/') st.push(A[i]);
        }
        else if(A[i]=='.'){
            if((i+1)!=n && A[i+1]=='.'){
                st.pop();
                while(!st.empty() && st.top()!='/') st.pop();
                if(st.empty()) st.push('/');
                i++;
            }
        }
        else st.push(A[i]);
    }
    
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    if(ans.size()>1 && ans[ans.size()-1]=='/') ans.pop_back();
    
    return ans;
    
}
