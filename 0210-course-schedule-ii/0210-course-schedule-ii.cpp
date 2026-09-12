// O(V + E) time and O(V) space
class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adjList, vector<int>& visited, stack<int>& st){
        visited[node] = 1;
        for(auto neighbor : adjList[node]){
            if(visited[neighbor] == 1) return true;
            if(visited[neighbor] == 0){
                if(dfs(neighbor, adjList, visited, st)) return true;
            }
        }
        visited[node] = 2;
        st.push(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for (auto& edge : prerequisites) {
            int course = edge[0];
            int prereq = edge[1];
            adjList[prereq].push_back(course);
        }
        vector<int> visited(numCourses, 0);
        stack<int> st;
        for(int i=0; i<numCourses; i++){
            if(!visited[i]){
                if(dfs(i, adjList, visited, st)){
                    return {};
                }
            }
        }
        vector<int> topoOrder;
        while(!st.empty()){
            topoOrder.push_back(st.top());
            st.pop();
        }
        return topoOrder;
    }
};