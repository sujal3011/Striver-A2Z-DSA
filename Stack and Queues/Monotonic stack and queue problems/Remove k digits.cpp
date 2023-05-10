#include<bits/stdc++.h>
using namespace std;

//Optimal solution
//Explanation--->Techdose video
//Using stack
//Time complexity---O(n)
//Space complexity-->O(n)
string removeKdigits(string num, int k) {
        int n=num.size();
        stack<char>st;
        for(auto c:num){
            
            while(!st.empty() && st.top()>c && k>0){  //Whenever there is a dip in the value of the digit we will process it.
                st.pop();
                k--;
            }
            if(!st.empty() || c!='0') st.push(c);

        }
        //After execution of the while loop the string(number) will be in ascending order(sorted) 
        //When k is larger than the number of dips present in the string
        while(!st.empty() && k--){
            st.pop();
        }
        if(st.empty()) return "0";

        //Reusing the string num
        while(!st.empty()){
            num[n-1]=st.top();
            st.pop();
            n--;
        }
        return num.substr(n);
}

int main(){

    return 0;
}