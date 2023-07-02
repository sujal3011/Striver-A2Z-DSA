#include<bits/stdc++.h>
using namespace std;

//Using the concept of maximum area in a histogram
//Time complexity-->O(n) * O(n + m)
//Space complexity-->O(n)
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

    int maximalRectangle(vector<vector<char>>& matrix) {

        int m=matrix.size(),n=matrix[0].size();
        vector<int>height(n,0);
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1') height[j]++;
                else height[j]=0;
            }
            ans=max(ans,largestRectangleArea(height));
        }

        return ans;
}

        
