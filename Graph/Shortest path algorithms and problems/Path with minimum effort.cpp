#include<bits/stdc++.h>
using namespace std;

//Using Dijkstra Algorithm
//Time complexity--->ElogV---->(n x m x 4)log(n x m)    
int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});

        int X[]={0,1,0,-1};
        int Y[]={1,0,-1,0};

        while(!pq.empty()){
            int nodeX=pq.top().second.first;
            int nodeY=pq.top().second.second;
            int diff=pq.top().first;
            pq.pop();

            for(int i=0;i<4;i++){
                int adjX=nodeX+X[i];
                int adjY=nodeY+Y[i];
                if(adjX>=0 && adjX<n && adjY>=0 && adjY<m ){

                int newDiff=abs(heights[nodeX][nodeY]-heights[adjX][adjY]);
                int newEffort =max(diff,newDiff);  //maximizing the difference to get the effort

                if(dist[adjX][adjY] > newEffort){

                    dist[adjX][adjY]=newEffort;  //minimizing the effort to reach the particular node
                    pq.push({newEffort,{adjX,adjY}});
                }
                }
            }
        }
        return dist[n-1][m-1];


    }