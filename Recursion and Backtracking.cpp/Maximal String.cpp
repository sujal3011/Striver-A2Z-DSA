#include <bits/stdc++.h>
using namespace std;

void solveMaxString(string &s,string &maxString,int k){
    
    if(s>maxString) maxString=s;
    if(k==0) return;
    
    for(int i=0;i<s.length()-1;i++){
        for(int j=i+1;j<s.length();j++){
            if(s[j]>s[i]){
                swap(s[i],s[j]);
                solveMaxString(s,maxString,k-1);
                //swap(s[i],s[j]);
            }
        }
    }
}
string solve(string A, int B) {
    
    string ans="";
    solveMaxString(A,ans,B);
    return ans;
    
}
