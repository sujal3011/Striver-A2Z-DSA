#include<bits/stdc++.h>
using namespace std;


//Time complexity-->O(E*logE) + O(E*logE)
//Space complexity--->O(E) + O(N),proiority queue and visited array
int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int>visited(V,0);
        int sum=0;
        pq.push({0,0});
        // at max we are inserting all the edges in the priority queue
        // E iterations
        while(!pq.empty()){

            //E*log E
            int node=pq.top().second;
            int weight=pq.top().first;
            pq.pop();
            if(!visited[node]){
                visited[node]=1;
                sum+=weight;
                //E*log E
                for(auto it:adj[node]){
                    int child=it[0];
                    int edgeWeight=it[1];
                    if(!visited[child]){
                        pq.push({edgeWeight,child});
                    }
                }
            }
            
        }
        return sum;
    }