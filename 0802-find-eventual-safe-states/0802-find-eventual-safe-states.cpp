// Approach 1 : Using DFS
// A node which is a part of a cycle or leads to a cycle can never be a safe node.
// O(V + E) time and O(3V) space
class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& visited, vector<int>& pathVisited, vector<int>& check){
        visited[node] = 1;
        pathVisited[node] = 1;
        for(auto neighbor : graph[node]){
            if(!visited[neighbor]){
                if(dfs(neighbor, graph, visited, pathVisited, check) == true) return true;
            }
            else if(pathVisited[neighbor]) return true;
        }
        check[node] = 1;
        pathVisited[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> visited(V, 0);
        vector<int> pathVisited(V, 0);
        vector<int> safeNodes;
        vector<int> check(V, 0);
        for(int i=0; i<V; i++){
            if(!visited[i]){
                dfs(i, graph, visited, pathVisited, check);
            }
        }
        for(int i=0; i<V; i++){
            if(check[i] == 1) safeNodes.push_back(i);
        }
        return safeNodes;
    }
};

// Approach 2 : Using Topological Sort\
// O() time and O() space
// class Solution {
// public:
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
//     }
// };