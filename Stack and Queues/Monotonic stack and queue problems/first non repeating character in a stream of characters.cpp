#include <bits/stdc++.h>
using namespace std;


//Time complexity--->O(n)
//Space complexity--->O(n) + O(n)
string solve(string A) {
    
    int n=A.size();
    queue<char>q;
    vector<int>freq(26,0);
    string ans="";
    for(int i=0;i<n;i++){
        if(freq[A[i]-'a']==0) q.push(A[i]);
        freq[A[i]-'a']++;
        
        while(!q.empty() && freq[q.front()-'a']>1) q.pop();
        if(q.empty()) ans+='#';
        else ans+=q.front();
         
    }
    
    return ans;
}
