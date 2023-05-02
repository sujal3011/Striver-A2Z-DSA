#include<bits/stdc++.h>
using namespace std;


//Time complexity--->O(n)
//Space complexity--->O(1)
bool isIsomorphic(string s, string t) {
        int n=s.length();
        vector<int>mm1(128,-1),mm2(128,-1);
        bool flag=true;
        for(int i=0;i<n;i++){
            char ch1=s[i],ch2=t[i];
            if(mm1[int(ch1)]!=-1 && mm1[int(ch1)]!=int(ch2)){
                flag=false;
                break;
            }

            if(mm2[int(ch2)]!=-1 && mm2[int(ch2)]!=int(ch1)){
                flag=false;
                break;
            }

            mm1[int(ch1)]=int(ch2);
            mm2[int(ch2)]=int(ch1);
            
        }

        return flag;
    }

int main(){
    return 0;
}

