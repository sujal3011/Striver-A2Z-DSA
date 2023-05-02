#include<bits/stdc++.h>
using namespace std;

//Approach 1
//Time complexity--->O(n)
//Space complexity--->O(n)
int maxDepth(string s) {
        stack<int>st;
        int cnt=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                if(cnt<st.size()){
                    cnt=st.size();
                }
                st.pop();
            }
        }

        return cnt;
}

//Approach 1
//Time complexity--->O(n)
//Space complexity--->O(1)
int maxDepth(string s) {
        int n=s.length(),cnt=0,max_cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                cnt++;
            }
            if(s[i]==')'){
                if(max_cnt<cnt){
                    max_cnt=cnt;
                }
                cnt--;
            }
        }

        return max_cnt;
}

int main(){
    return 0;
}

