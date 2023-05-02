#include<bits/stdc++.h>
using namespace std;

//Approach 1
//Time complexity--->O(nlogn)
//Space complexity--->O(n)

bool cmp(pair<char,int>&a,pair<char,int>&b){
        return a.second < b.second;
}

string frequencySort(string s) {
        map<char,int>mm;
        int n=s.length();
        for(int i=0;i<n;i++){
            mm[s[i]]++;
        }

        vector<pair<char,int>>vec;
        for(auto it:mm) vec.push_back(it);
        sort(vec.begin(),vec.end(),cmp);

        string ans="";

        for(auto it=vec.rbegin();it!=vec.rend();it++){
            for(int i=0;i<it->second;i++){
                ans+=it->first;
            }
        }

        return ans;
    }


//Approach 2


int main(){
    return 0;
}

