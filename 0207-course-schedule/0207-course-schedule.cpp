// Approoach 1 : Using DFS (Detecting a Cycle)
// O(V + E) time and O(3V) space
// class Solution {
// public:
//     bool dfs(int node, vector<vector<int>>& adjList, vector<int>& visited, vector<int>& pathVisited){
//         visited[node] = 1;
//         pathVisited[node] = 1;
//         for(auto neighbor : adjList[node]){
//             if(!visited[neighbor]){
//                 if(dfs(neighbor, adjList, visited, pathVisited) == true) return true;
//             }
//             else if(pathVisited[neighbor]) return true;
//         }
//         pathVisited[node] = 0;
//         return false;
//     }
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<vector<int>> adjList(numCourses);
//         for (auto& edge : prerequisites) {
//             adjList[edge[1]].push_back(edge[0]);
//         }
//         vector<int> visited(numCourses, 0);
//         vector<int> pathVisited(numCourses, 0);
//         for(int i=0; i<numCourses; i++){
//             if(!visited[i]){
//                 if(dfs(i, adjList, visited, pathVisited) == true) return false;
//             }
//         }
//         return true;
//     }
// };

// Approach 2 : Using BFS (Topological Sort)
// O(V + E) time and O(V) space
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for (auto& edge : prerequisites) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> topoOrder;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topoOrder.push_back(node);
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        if(topoOrder.size() == numCourses) return true;
        return false;
    }
};