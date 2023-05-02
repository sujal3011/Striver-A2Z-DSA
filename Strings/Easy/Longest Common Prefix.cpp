#include<bits/stdc++.h>
using namespace std;


//Time complexity--->O(n*m), where n=strs.length,m=strs[i].length
//Space complexity--->O(1)
string longestCommonPrefix(vector<string>& strs) {
        string ans=strs[0];
        for(int i=1;i<strs.size();i++){
            int j=0;
            string temp="";
            while(j<ans.length() && j<strs[i].length()){
                if(ans[j]==strs[i][j]){
                    temp+=ans[j];
                    j++;
                }
                else break;
            }
            ans=temp;
        }
        return ans;
}

int main(){
    return 0;
}

