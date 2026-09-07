// Approach 1 : Using BFS
// O(nm) time and O(min(n, m)) space
// class Solution {
// public:
//     void bfs(int row, int col, vector<vector<int>>& visited, vector<vector<char>>& grid){
//         int n = grid.size();
//         int m = grid[0].size();
//         visited[row][col] = 1;
//         queue<pair<int, int>> q;
//         q.push({row, col});
//         while(!q.empty()){
//             int row = q.front().first;
//             int col = q.front().second;
//             q.pop();
//             for(int delRow=-1; delRow<=1; delRow++){
//                 for(int delCol=-1; delCol<=1; delCol++){
//                     int nbrRow = row + delRow;
//                     int nbrCol = col + delCol;

//                 }
//             }
//         }
//     }
//     int numIslands(vector<vector<char>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         int islands = 0;
//         vector<vector<int>> visited(n, vector<int>(m, 0));
//         for(int row=0; row<n; row++){
//             for(int col=0; col<m; col++){
//                 if(!visited[row][col]){
//                     islands++;
//                     bfs(row, col, visited, grid);
//                 }
//             }
//         }
//         return islands;
//     }
// };


// Approach 2 : Using DFS
// O(nm) time and O(nm) space
class Solution {
private:
    void dfs(vector<vector<char>>& grid, int r, int c, int m, int n) {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != '1') return;
        grid[r][c] = '0';
        dfs(grid, r + 1, c, m, n);
        dfs(grid, r - 1, c, m, n);
        dfs(grid, r, c + 1, m, n);
        dfs(grid, r, c - 1, m, n);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        int islandCount = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ++islandCount;
                    dfs(grid, i, j, m, n);
                }
            }
        }
        return islandCount;
    }
};