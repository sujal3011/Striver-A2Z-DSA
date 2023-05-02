#include<bits/stdc++.h>
using namespace std;

//Brute force approach (using stack)
//Time complexity--->O(n)
//Space complexity--->O(n)

//Optimized approach
//Time complexity--->O(n)
//Space complexity--->O(1)
string reverseWords(string s) {
        int n=s.length(),i=-1,j=-1;
        string ans="";
        for(i=n-1;i>=0;i--){
            
            if(s[i]==' '){
                if(j!=-1){
                ans+=s.substr(i+1,j-i)+" ";
                j=-1;
                }
            }
            else if(j==-1) j=i;   
        }

        if(j!=-1) ans+=s.substr(i+1,j-i);
        if(ans[ans.length()-1]==' ') ans=ans.substr(0,ans.length()-1);
        return ans;
}

int main(){
    return 0;
}

