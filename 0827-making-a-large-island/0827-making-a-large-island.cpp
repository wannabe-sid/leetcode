// Using Disjoint Set Data Structure
// Formula(row, col) = row * no. of columns + col
// O() time and O() space
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
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        for(int row=0; row<n; row++){
            for(int col=0; col<n; col++){
                if(grid[row][col] == 0) continue;
                int drow[] = {-1, 0, 1, 0};
                int dcol[] = {0, -1, 0, 1};
                for(int i=0; i<4; i++){
                    int nrow = row + drow[i];
                    int ncol = col + dcol[i];
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n){
                        if(grid[nrow][ncol] == 1){
                            int node = row * n + col;
                            int adjNode = nrow * n + ncol;
                            ds.unionBySize(node, adjNode);
                        }
                    }
                }
            }
        }
        int largest = 0;
        for(int row=0; row<n; row++){
            for(int col=0; col<n; col++){
                if(grid[row][col] == 1) continue;
                int drow[] = {-1, 0, 1, 0};
                int dcol[] = {0, -1, 0, 1};
                set<int> components;
                for(int i=0; i<4; i++){
                    int nrow = row + drow[i];
                    int ncol = col + dcol[i];
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n){
                        if(grid[nrow][ncol] == 1){
                            components.insert(ds.findParent(nrow * n + ncol));
                        }
                    }
                }
                int totalSize = 1;
                for(auto& it : components){
                    totalSize += ds.size[it];
                }
                largest = max(largest, totalSize);
            }
        }
        return largest;
    }
};