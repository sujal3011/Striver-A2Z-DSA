#include <bits/stdc++.h>
using namespace std;

void getletterCombinations(int idx,string &digits,vector<string> &ans,string &ds,vector<string> &letters){

        if(idx>=digits.size()){
            ans.push_back(ds);
            return;
        }

        string temp = letters[digits[idx] - '0'];
        for(int i=0;i<temp.size();i++){
            ds[idx] = temp[i];
            getletterCombinations(idx + 1,digits,ans,ds,letters);
        }
    }

vector<string> letterCombinations(string digits) {
    
    if(digits.length()==0) return {};

        vector<string>letters{"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        int n = digits.length();
        vector<string>ans;
        string ds(n,'.');
        getletterCombinations(0,digits,ans,ds,letters);
        return ans;
        
    }
