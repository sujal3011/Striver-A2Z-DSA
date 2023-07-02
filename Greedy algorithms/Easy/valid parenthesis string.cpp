#include<bits/stdc++.h>
using namespace std;

//Using 2 stacks
//Time complexity--->O(n)
//Space complexity--->O(2*n)
 bool checkValidString(string s) {
        int n=s.length();
        stack<char>st1,st2;
        for(int i=0;i<n;i++){
            if(s[i]=='(') st1.push(i);
            else if(s[i]=='*') st2.push(i);
            else{
                if(!st1.empty()) st1.pop();
                else if(!st2.empty()) st2.pop();
                else return false;
            }
        }
        while(!st1.empty()){
            if(st2.empty() || st2.top()<st1.top()) return false;
            else{
                st2.pop();
                st1.pop();
            }
        }
        return true;
    }