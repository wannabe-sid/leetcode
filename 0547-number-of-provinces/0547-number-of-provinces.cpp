// Approach 1 : Using DFS
// O(V^2) time and O(V) space
// class Solution {
// public:
//     void dfs(int u, vector<int>& visited, vector<vector<int>>& isConnected){
//         visited[u] = 1;
//         for(int v=0; v<isConnected.size(); v++){
//             if(isConnected[u][v] == 1 && !visited[v]){
//                 dfs(v, visited, isConnected);
//             }
//         }
//     }
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int V = isConnected.size();
//         vector<int> visited(V, 0);
//         int result = 0;
//         for(int i=0; i<V; i++){
//             if(!visited[i]){
//                 result++;
//                 dfs(i, visited, isConnected);
//             }
//         }
//         return result;
//     }
// };

// Approach 2 : Using Disjoint Set 
// O(V^2) time and O(n*m) space
class DisjointSet{
    vector<int> rank, size, parent;
public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }
    int findParent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }
    void unionByRank(int u, int v){
        int ultParentU = findParent(u);
        int ultParentV = findParent(v);
        if(rank[ultParentU] < rank[ultParentV]){
            parent[ultParentU] = ultParentV;
        }
        else if(rank[ultParentV] < rank[ultParentU]){
            parent[ultParentV] = ultParentU;
        }
        else{
            parent[ultParentV] = ultParentU;
            rank[ultParentU]++;
        }
    }
    void unionBySize(int u, int v){
        int ultParentU = findParent(u);
        int ultParentV = findParent(v);
        if(size[ultParentU] < size[ultParentV]){
            parent[ultParentU] = ultParentV;
            size[ultParentV] += size[ultParentU];
        }
        else{
            parent[ultParentV] = ultParentU;
            size[ultParentU] += size[ultParentV];
        }
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        DisjointSet ds(V);
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(isConnected[i][j] == 1){
                    ds.unionByRank(i, j);
                }
            }
        }
        int count = 0;
        for(int i=0; i<V; i++){
            if(ds.findParent(i) == i){
                count++;
            } 
        }
        return count;
    }
};