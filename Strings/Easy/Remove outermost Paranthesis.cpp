#include<bits/stdc++.h>
using namespace std;

//Time complexity--->O(n)
//Space complexity--->O(n)
string removeOuterParentheses(string s) {
        int n=s.length();
        string ans;
        stack<int>ss;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(ss.empty()){
                    ss.push(s[i]);
                }
                else{
                    ans.push_back(s[i]);
                    ss.push(s[i]);
                }
            }
            else{
                ss.pop();
                if(!ss.empty()){
                    ans.push_back(s[i]);
                }
            }
        }

        return ans;
}

//Optoimized approach
//Time complexity--->O(n)
//Space complexity--->O(1)
string removeOuterParentheses(string s) {
        int n=s.length(), cnt=0;
        string ans;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(cnt==0){
                    cnt++;
                }
                else{
                    cnt++;
                    ans.push_back(s[i]);
                }
            }
            else{
                cnt--;
                if(cnt!=0){
                    ans.push_back(s[i]);
                }
            }
        }
        
        return ans;
}

int main(){
    return 0;
}

