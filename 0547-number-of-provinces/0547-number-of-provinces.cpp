// O(V^2) time and O(V) space
class Solution {
public:
    void dfs(int u, vector<int>& visited, vector<vector<int>>& isConnected){
        visited[u] = 1;
        for(int v=0; v<isConnected.size(); v++){
            if(isConnected[u][v] == 1 && !visited[v]){
                dfs(v, visited, isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int> visited(V, 0);
        int result = 0;
        for(int i=0; i<V; i++){
            if(!visited[i]){
                result++;
                dfs(i, visited, isConnected);
            }
        }
        return result;
    }
};