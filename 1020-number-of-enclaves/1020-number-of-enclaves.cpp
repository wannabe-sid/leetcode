// O(m * n) time and O(m * n) space
class Solution {
public:
    void dfs(int r, int c, int m, int n, vector<vector<int>>& grid){
        if(r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0) return;
        grid[r][c] = 0;
        dfs(r+1, c, m, n, grid);
        dfs(r-1, c, m, n, grid);
        dfs(r, c+1, m, n, grid);
        dfs(r, c-1, m, n, grid);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // Traverse first and last columns
        for(int i=0; i<m; i++){
            if(grid[i][0] == 1) dfs(i, 0, m, n, grid);
            if(grid[i][n-1] == 1) dfs(i, n-1, m, n, grid);
        }
        // Traverse first and last rows
        for(int i=0; i<n; i++){
            if(grid[0][i] == 1) dfs(0, i, m, n, grid);
            if(grid[m-1][i] == 1) dfs(m-1, i, m, n, grid);
        }
        int enclaves = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1) enclaves++;
            }
        }
        return enclaves;
    }
};