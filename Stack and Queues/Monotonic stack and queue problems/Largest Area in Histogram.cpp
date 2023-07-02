#include<bits/stdc++.h>
using namespace std;

//Approach 1
//Time complexity-->O(n) + O(n) + O(n)
//Space complexity-->O(3*n)
//2 pass solution
int largestRectangleArea(vector<int>& heights) {

        int n=heights.size();
        vector<int>leftSmaller(n),rightSmaller(n);
        stack<int>st;

        //Calculating left smaller 

        for(int i=0;i<n;i++){

            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            if(st.empty()) leftSmaller[i]=0;
            else leftSmaller[i]=st.top() + 1;
            st.push(i);
        }

        //Calculating the right smaller

        while(!st.empty()) st.pop();

        for(int i=n-1;i>=0;i--){

            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            if(st.empty()) rightSmaller[i]=n-1;
            else rightSmaller[i]=st.top() - 1;
            st.push(i);
        }

        for(int i=0;i<n;i++) cout<<leftSmaller[i]<<" ";
        cout<<endl;

        for(int i=0;i<n;i++) cout<<rightSmaller[i]<<" ";
        cout<<endl;

        int ans=0;

        for(int i=0;i<n;i++){
            int area = heights[i] * (rightSmaller[i]-leftSmaller[i]+1);
            ans=max(ans,area); 
        }
        return ans;

}


//Approach 2
//Time complexity-->O(n)
//Space complexity-->O(n)
//1 pass solution
int largestRectangleArea(vector<int>& heights) {

        int n=heights.size();
        int maxArea=0;
        stack<int>st;

        for(int i=0;i<=n;i++){   //IMPORTANT (running loop from 0 to n)
            while(!st.empty() && (i==n || heights[st.top()]>=heights[i])){
                int height=heights[st.top()];
                st.pop();
                int width;
                if(st.empty()) width=i;
                else width=i-st.top()-1;
                int area=height*width;
                maxArea=max(maxArea,area);
            }
            st.push(i);
        }
        return maxArea;
}

int main(){

    return 0;
}