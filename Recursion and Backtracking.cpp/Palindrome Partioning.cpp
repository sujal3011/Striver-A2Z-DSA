#include<bits/stdc++.h>
using namespace std;


 bool isPalindrome(string &str,int low,int high){

        int i=low,j=high;
        while(i<=j){
            if(str[i]!=str[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void partitionString(int idx,string &s,vector<string> &ds,vector<vector<string>> &ans){

        if(idx>=s.length()){
            ans.push_back(ds);
            return;
        }

        for(int i=idx;i<s.length();i++){

            if(isPalindrome(s,idx,i)){
                ds.push_back(s.substr(idx,i-idx+1));
                partitionString(i + 1,s,ds,ans);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {

        vector<vector<string>>ans;
        vector<string>ds;
        partitionString(0,s,ds,ans);
        return ans;
        
    }