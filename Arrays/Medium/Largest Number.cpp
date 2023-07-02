#include<bits/stdc++.h>
using namespace std;

//Interviewbit
string IntegerToString(int num){
    
    if(num==0) return "0";
    string ans = "";
    while(num > 0){
        char digit = '0' + (num%10);
        ans = digit + ans;
        num/=10;    
    }
    return ans;
}

bool comp(int n1,int n2){
    
    string s1=IntegerToString(n1);
    string s2=IntegerToString(n2);
    if((s1 + s2) > (s2 + s1)) return true;
    return false;

}

string largestNumber(const vector<int> &A) {
    
    bool flag=0;
    int n=A.size();
    for(int i=0;i<n;i++){
        if(A[i]!=0){
            flag=1;
            break;
        }
    }

    if(!flag) return "0";
    vector<int>arr=A;
    sort(arr.begin(),arr.end(),comp);
    
    string res = "";
    for(int i=0;i<n;i++) res +=IntegerToString(arr[i]);
    return res;

}