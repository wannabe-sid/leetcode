// Approach 1 : Using DFS
// A node which is a part of a cycle or leads to a cycle can never be a safe node.
// O(V + E) time and O(3V) space
// class Solution {
// public:
//     bool dfs(int node, vector<vector<int>>& graph, vector<int>& visited, vector<int>& pathVisited, vector<int>& check){
//         visited[node] = 1;
//         pathVisited[node] = 1;
//         for(auto neighbor : graph[node]){
//             if(!visited[neighbor]){
//                 if(dfs(neighbor, graph, visited, pathVisited, check) == true) return true;
//             }
//             else if(pathVisited[neighbor]) return true;
//         }
//         check[node] = 1;
//         pathVisited[node] = 0;
//         return false;
//     }
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         int V = graph.size();
//         vector<int> visited(V, 0);
//         vector<int> pathVisited(V, 0);
//         vector<int> safeNodes;
//         vector<int> check(V, 0);
//         for(int i=0; i<V; i++){
//             if(!visited[i]){
//                 dfs(i, graph, visited, pathVisited, check);
//             }
//         }
//         for(int i=0; i<V; i++){
//             if(check[i] == 1) safeNodes.push_back(i);
//         }
//         return safeNodes;
//     }
// };

// Approach 2 : Using 3 State DFS
// O(V + E) time and O(V) space
// class Solution {
// public:
//     bool dfs(int node, const vector<vector<int>>& graph, vector<int>& visited) {
//         // visited[node] = 1 -> visiting (active in current recursion stack)
//         // visited[node] = 2 -> safe (fully processed and leads to no cycle)
//         visited[node] = 1;
//         for (int neighbor : graph[node]) {
//             if (visited[neighbor] == 1) {
//                 return true; // Cycle detected
//             }
//             if (visited[neighbor] == 0) {
//                 if (dfs(neighbor, graph, visited)) {
//                     return true;
//                 }
//             }
//         }
//         visited[node] = 2; // Mark node as safe
//         return false;
//     }
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         int n = graph.size();
//         // 0 = unvisited, 1 = visiting, 2 = safe
//         vector<int> visited(n, 0);
//         for (int i=0; i<n; i++) {
//             if (visited[i] == 0) {
//                 dfs(i, graph, visited);
//             }
//         }
//         vector<int> safeNodes;
//         for (int i = 0; i < n; i++) {
//             if (visited[i] == 2) {
//                 safeNodes.push_back(i);
//             }
//         }
//         return safeNodes;
//     }
// };

// Approach 3 : Using BFS (Topological Sort)
// O(V + E) time and O(V) space
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> revGraph(n);
        vector<int> inDegree(n, 0);
        // Reverse edges and track in-degrees
        for (int u = 0; u < n; u++) {
            for (int v : graph[u]) {
                revGraph[v].push_back(u);
                inDegree[u]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> safeNodes;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for (int neighbor : revGraph[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};