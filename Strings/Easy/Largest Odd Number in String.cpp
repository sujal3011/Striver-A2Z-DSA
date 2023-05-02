#include<bits/stdc++.h>
using namespace std;

//Optimized approach
//Time complexity--->O(n)
//Space complexity--->O(1)
string largestOddNumber(string num) {
        int n=num.length(),i;
        for(i=n-1;i>=0;i--){
            if((num[i]-'0')&1){
                break;
            }
        }
        if(i==-1) return "";
        return num.substr(0,i+1);
}

int main(){
    return 0;
}

