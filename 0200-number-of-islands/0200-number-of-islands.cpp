// Approach 1 : Using BFS
// O(n*m) time and O(min(n, m)) space
class Solution {
public:
    void bfs(int startRow, int startCol, vector<vector<int>>& visited, const vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        visited[startRow][startCol] = 1;
        queue<pair<int, int>> q;
        q.push({startRow, startCol});
        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};      
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nbrRow = r + dRow[i];
                int nbrCol = c + dCol[i];
                if (nbrRow >= 0 && nbrRow < n && nbrCol >= 0 && nbrCol < m 
                    && grid[nbrRow][nbrCol] == '1' && visited[nbrRow][nbrCol] == 0) {
                    visited[nbrRow][nbrCol] = 1;
                    q.push({nbrRow, nbrCol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int n = grid.size();
        int m = grid[0].size();
        int islands = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (!visited[row][col] && grid[row][col] == '1') {
                    islands++;
                    bfs(row, col, visited, grid);
                }
            }
        }
        return islands;
    }
};


// Approach 2 : Using DFS
// O(n*m) time and O(n*m) space
// class Solution {
// private:
//     void dfs(vector<vector<char>>& grid, int r, int c, int m, int n) {
//         if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != '1') return;
//         grid[r][c] = '0';
//         dfs(grid, r + 1, c, m, n);
//         dfs(grid, r - 1, c, m, n);
//         dfs(grid, r, c + 1, m, n);
//         dfs(grid, r, c - 1, m, n);
//     }
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         if (grid.empty() || grid[0].empty()) return 0;
//         int m = grid.size();
//         int n = grid[0].size();
//         int islandCount = 0;
//         for (int i = 0; i < m; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 if (grid[i][j] == '1') {
//                     ++islandCount;
//                     dfs(grid, i, j, m, n);
//                 }
//             }
//         }
//         return islandCount;
//     }
// };