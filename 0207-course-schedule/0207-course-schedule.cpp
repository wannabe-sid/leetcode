// O(V + E) time and O(3V) space
class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adjList, vector<int>& visited, vector<int>& pathVisited){
        visited[node] = 1;
        pathVisited[node] = 1;
        for(auto neighbor : adjList[node]){
            if(!visited[neighbor]){
                if(dfs(neighbor, adjList, visited, pathVisited) == true) return true;
            }
            else if(pathVisited[neighbor]) return true;
        }
        pathVisited[node] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for (auto& edge : prerequisites) {
            adjList[edge[1]].push_back(edge[0]);
        }
        vector<int> visited(numCourses, 0);
        vector<int> pathVisited(numCourses, 0);
        for(int i=0; i<numCourses; i++){
            if(!visited[i]){
                if(dfs(i, adjList, visited, pathVisited) == true) return false;
            }
        }
        return true;
    }
};