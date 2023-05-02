#include<bits/stdc++.h>
using namespace std;

//Brute force approach
//All rotations of A are contained in A+A. Thus, we can simply check whether B is a substring of A+A
//Time complexity--->O(n^2)
//Space complexity--->O(1)
bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()) return false;
        int n=s.length();
        string str=s+s;
        for(int i=0;i<=n;i++){
            if(str.substr(i,n)==goal) return true;
        }
        return false;
}


int main(){
    return 0;
}

