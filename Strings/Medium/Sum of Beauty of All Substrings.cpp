#include<bits/stdc++.h>
using namespace std;

//Time complexity--->O(n^2*26)
//Space complexity--->O(1)
int beautySum(string s) {
        int n=s.length();
        int ans=0;
        vector<int>freq(26,0);

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;
                int maxi=INT_MIN,mini=INT_MAX;
                for(int k=0;k<26;k++){
                    maxi=max(maxi,freq[k]);
                    if(freq[k]!=0) mini=min(mini,freq[k]);
                }
                if(mini!=INT_MAX) ans+=(maxi-mini);
            }
            for(int k=0;k<26;k++) freq[k]=0;
        }
        return ans;
}

int main(){
    string str="aabcb";
    cout<<beautySum(str)<<endl;
    return 0;
}

