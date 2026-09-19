// O(E) time and O(V+E) space
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto& edge : flights){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
        }
        vector<int> distance(n, INT_MAX);
        distance[src] = 0;
        queue<pair<int, pair<int, int>>> q; // queue<pair<stops, pair<node, distance>>> q;
        q.push({0, {src, 0}});
        while(!q.empty()){
            int stops = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();
            if(stops > k) continue;
            for(auto it : adj[node]){
                int adjNode = it.first;
                int edgeWeight = it.second;
                if(cost + edgeWeight < distance[adjNode] && stops <= k){
                    distance[adjNode] = cost + edgeWeight;
                    q.push({stops + 1, {adjNode, cost + edgeWeight}});
                }
            }
        }
        if(distance[dst] == INT_MAX) return -1;
        return distance[dst];
    }
};