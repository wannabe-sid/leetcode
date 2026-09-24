// Tarjan's Algorithm
// tin[] = DFS time of insertion
// low[] = minimum of the lowest time of insertion of all adjacent nodes apart from parent
// O(V+E) time and O(V+E) space
class Solution {
public:
    int timer = 0;
    void dfs(int node, int parent, vector<int>& visited, vector<vector<int>>& adj, vector<vector<int>>& bridges, vector<int>& tin, vector<int>& low){
        
        visited[node] = 1;
        tin[node] = timer;
        low[node] = timer;
        timer++;
        for(auto& adjNode : adj[node]){
            if(adjNode == parent) continue;
            if(!visited[adjNode]){
                dfs(adjNode, node, visited, adj, bridges, tin, low);
                low[node] = min(low[node], low[adjNode]);
                if(low[adjNode] > tin[node]){
                    bridges.push_back({adjNode, node});
                }
            }
            else{
                low[node] = min(low[node], low[adjNode]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto& edge : connections){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> visited(n, 0);
        vector<int> tin(n, 0);
        vector<int> low(n, 0);
        vector<vector<int>> bridges;
        dfs(0, -1, visited, adj, bridges, tin, low);
        return bridges;
    }
};