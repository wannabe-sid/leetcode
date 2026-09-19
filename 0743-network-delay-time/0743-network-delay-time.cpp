// O(ElogV) time and O(V+E) space
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& edge : times) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
        }
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        // Min-heap: {current_delay, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        while (!pq.empty()) {
            int currTime = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto& it : adj[node]) {
                int adjNode = it.first;
                int time = it.second;
                if (dist[node] + time < dist[adjNode]) {
                    dist[adjNode] = dist[node] + time;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        int maxTime = 0;
        for(int i=1; i<=n; i++){
            if(dist[i] == INT_MAX) return -1; 
            maxTime = max(maxTime, dist[i]);
        }
        return maxTime;
    }
};