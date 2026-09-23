// Using Disjoint Set Data Structure
// Formula(row, col) = row * no. of columns + col
// Time Complexity: O(N * alpha(maxRow + maxCol))
// Space Complexity: O(maxRow + maxCol)
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
        if(ultParentU == ultParentV) return;
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
// Let total stones = n
// Let component ci has xi stones
// We can remove total of (x1-1)+(x2-1)+...+(xn-1) stones
// = (x1+x2+...+xn)-(1+1+...+1)
// So, total stones we can remove = total stones - no. of components
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0;
        int maxCol = 0;
        for(auto& it : stones){
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        DisjointSet ds(maxRow + maxCol + 1);
        unordered_map<int, int> stoneNodes;
        for(auto& it : stones){
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;
            ds.unionBySize(nodeRow, nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }
        int count = 0;
        for(auto& it : stoneNodes){
            if(ds.findParent(it.first) == it.first){
                count++;
            }
        }
        return n - count;
    }
};