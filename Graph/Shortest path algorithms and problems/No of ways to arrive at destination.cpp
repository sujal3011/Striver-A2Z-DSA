#include<bits/stdc++.h>
using namespace std;

//Modified Dijkstra algorithm
//Using the ways
int countPaths(int n, vector<vector<int>> &roads)
    {
        // Creating an adjacency list for the given graph.
        vector<pair<int, int>> adj[n];
        for (auto it : roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        // Defining a priority queue (min heap). 
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Initializing the dist array and the ways array
        // along with their first indices.
        vector<int> dist(n, 1e9), ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        // Define modulo value
        int mod = (int)(1e9 + 7);

        // Iterate through the graph with the help of priority queue
        // just as we do in Dijkstra's Algorithm.
        while (!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int edW = it.second;

                // This ‘if’ condition signifies that this is the first
                // time we’re coming with this short distance, so we push
                // in PQ and keep the no. of ways the same.
                if (dis + edW < dist[adjNode])
                {
                    dist[adjNode] = dis + edW;
                    pq.push({dis + edW, adjNode});
                    ways[adjNode] = ways[node];
                }

                // If we again encounter a node with the same short distance
                // as before, we simply increment the no. of ways.
                else if (dis + edW == dist[adjNode])
                {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        // Finally, we return the no. of ways to reach
        // (n-1)th node modulo 10^9+7.
        return ways[n - 1] % mod;
}


//Modified solution
//Without using ways array ,instead storing pair {distance,ways} in dist array itself
#define ll long long
class Solution {
public:
    int M=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<ll,ll>>>adj(n);
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
        vector<pair<ll,ll>>dist(n);
        for(ll i=0;i<n;i++){
            dist[i]={LONG_MAX,0};
        }
        dist[0]={0,1};
        pq.push({0,0});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            ll node=it.second;
            ll distance=it.first;
            for(auto it:adj[node]){
                ll child=it.first;
                ll weight=it.second;
                if((distance+weight)==dist[child].first){
                    dist[child].second = (dist[child].second+dist[node].second)%M;
                }
                else if((distance+weight)<dist[child].first){
                    dist[child].first=distance+weight;
                    dist[child].second=dist[node].second;
                    pq.push({distance+weight,child});
                }
            }
        }

        for(auto it:dist){
            cout<<it.first<<" "<<it.second<<endl;
        }

        return dist[n-1].second%M;

    }
};