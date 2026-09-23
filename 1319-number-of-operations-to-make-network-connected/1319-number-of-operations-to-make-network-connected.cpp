// O(V+E) time and O(V) space
class DisjointSet{
public:
    vector<int> rank, size, parent;
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int ans = 0;
        int extra = 0;
        for(auto& edge : connections){
            int u = edge[0];
            int v = edge[1];
            if(ds.findParent(u) == ds.findParent(v)) extra++;    
            else ds.unionBySize(u, v);
        }
        for(int i=0; i<n; i++){
            if(ds.parent[i] == i) ans++;
        }
        if(extra >= ans - 1) return ans - 1;
        return -1;
    }
};