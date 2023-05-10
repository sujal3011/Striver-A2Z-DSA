#include<bits/stdc++.h>
using namespace std;

//Brute force approach
//Time complexity--->O(n^3)
//Space complexity--->O(1)
string longestPalindrome(string s) {
        int n=s.length();string ans;
        int maxlen=INT_MIN;
        for(int i=0;i<n;i++){
            string str="";
            for(int j=i;j<n;j++){
                str+=s[j];
                string temp=str;
                reverse(temp.begin(),temp.end());
                if(str==temp){
                    if((j-i+1)>maxlen){
                        maxlen=j-i+1;
                        ans=str;
                    }
                }
            }
        }
        return ans;
    }

int main(){

    return 0;
}

//DP Solutions

