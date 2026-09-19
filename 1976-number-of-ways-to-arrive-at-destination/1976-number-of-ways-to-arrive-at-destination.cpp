// O(ElogV) time and O(V+E) space
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long mod = 1e9 + 7;
        // adj{neighbor, weight}
        vector<vector<pair<int, long long>>> adj(n);
        for (auto& edge : roads) {
            int u = edge[0];
            int v = edge[1];
            long long wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        vector<long long> distance(n, LLONG_MAX);
        distance[0] = 0;
        vector<long long> numOfWays(n, 0);
        numOfWays[0] = 1;
        // Min-heap storing {distance, node}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});
        while (!pq.empty()) {
            long long dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto& it : adj[node]) {
                int adjNode = it.first;
                long long edgeWeight = it.second;
                if (dist + edgeWeight < distance[adjNode]) {
                    distance[adjNode] = dist + edgeWeight;
                    numOfWays[adjNode] = numOfWays[node];
                    pq.push({distance[adjNode], adjNode});
                }
                else if (dist + edgeWeight == distance[adjNode]) {
                    numOfWays[adjNode] = (numOfWays[adjNode] + numOfWays[node]) % mod;
                }
            }
        }
        return numOfWays[n - 1];
    }
};