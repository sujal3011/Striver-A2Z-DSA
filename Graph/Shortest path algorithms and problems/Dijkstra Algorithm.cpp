#include<bits/stdc++.h>
using namespace std;


//Implemented using priority queue
//Time complexity-->O(ElogV)
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int>dist(V,1e9);
        dist[S]=0;
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,S});
        while(!pq.empty()){
            int node=pq.top().second;
            int distance=pq.top().first;
            pq.pop();
            for(auto it:adj[node]){
                int child=it[0];
                int weight=it[1];
                int total=distance + weight;
                if(total<dist[child]){
                    dist[child]=total;
                    pq.push({total,child});
                }
            }
            
        }
        
        return dist;
}

//Implemented using set
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int,int>>st;
        vector<int>dist(V,1e9);
        
        dist[S]=0;
        st.insert({0,S});
        
        while(!st.empty()){
            auto top=*(st.begin());
            int node=top.second;
            int distance=top.first;
            st.erase(top);
            
            for(auto it:adj[node]){
                int adjNode=it[0];
                int weight=it[1];
                
                if((distance+weight)<dist[adjNode]){
                    
                    if(dist[adjNode]!=1e9) st.erase({dist[adjNode],adjNode});
                    
                    dist[adjNode]=distance+weight;
                    st.insert({dist[adjNode],adjNode});
                    
                }
            }
        }
        return dist;
}