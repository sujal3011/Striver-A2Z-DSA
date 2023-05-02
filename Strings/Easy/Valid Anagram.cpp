#include<bits/stdc++.h>
using namespace std;

//Approach 1
//Sort both the strings and compare if they are equal or not
//Time complexity--->O(nlogn)
//Space complexity--->O(1)


//Approach 2
//Time complexity--->O(n)
//Space complexity--->O(1)
bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;

        int n=s.length();
        vector<int>freq1(26),freq2(26);
        for(int i=0;i<n;i++){
            freq1[s[i]-'a']++;
        }
        for(int i=0;i<n;i++){
            freq2[t[i]-'a']++;
        }

        for(int i=0;i<26;i++){
            if(freq1[i]!=freq2[i]) return false;
        }
        return true;
}

int main(){
    return 0;
}

