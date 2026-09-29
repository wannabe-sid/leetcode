// Recursion -> Memoization (Top Down)
// O(n*m) time and O(n*m) space and O(n+m) stack space
// class Solution {
// public:
//     int solve(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp){
//         if(i == 0 && j == 0) return grid[0][0];
//         if(i < 0 || j < 0) return INT_MAX;
//         if(dp[i][j] != -1) return dp[i][j];
//         int left = solve(i, j-1, n, m, grid, dp);
//         int up = solve(i-1, j, n, m, grid, dp);
//         return dp[i][j] = grid[i][j] + min(left, up);
//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<int>> dp(n, vector<int>(m, -1));
//         return solve(n-1, m-1, n, m, grid, dp);
//     }
// };

// Recursion -> Tabulation (Bottom Up)
// O(n*m) time and O(n*m) space and O(1) stack space
// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<int>> dp(n, vector<int>(m, -1));
//         dp[0][0] = grid[0][0];
//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 if(i == 0 && j == 0) continue;
//                 else{
//                     int left = INT_MAX;
//                     int up = INT_MAX;
//                     if(j > 0) left = grid[i][j] + dp[i][j-1];
//                     if(i > 0) up = grid[i][j] + dp[i-1][j];
//                     dp[i][j] = min(left, up);
//                 }
//             }
//         }
//         return dp[n-1][m-1];
//     }
// };

// Recursion -> Space Optimization
// O(n*m) time and O(n) space and O(1) stack space
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> prevRow(m, 0);
        for(int i=0; i<n; i++){
            vector<int> currRow(m, 0);
            for(int j=0; j<m; j++){
                if(i == 0 && j == 0) currRow[j] = grid[i][j];
                else{
                    int left = INT_MAX;
                    int up = INT_MAX;
                    if(j > 0) left = grid[i][j] + currRow[j-1];
                    if(i > 0) up = grid[i][j] + prevRow[j];
                    currRow[j] = min(left, up);
                }
            }
            prevRow = currRow;
        }
        return prevRow[m-1];
    }
};