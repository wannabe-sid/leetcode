// Recursion -> Memoization (Top Down)
// O(n*m) time and O(n*m) space and O(n+m) stack space
class Solution {
public:
    int solve(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i == 0 && j == 0) return grid[0][0];
        if(i < 0 || j < 0) return INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        int left = solve(i, j-1, n, m, grid, dp);
        int up = solve(i-1, j, n, m, grid, dp);
        return dp[i][j] = grid[i][j] + min(left, up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n-1, m-1, n, m, grid, dp);
    }
};

// Recursion -> Tabulation (Bottom Up)
// O() time and O() space and O() stack space
// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
        
//     }
// };

// Recursion -> Space Optimization
// O() time and O() space and O() stack space
// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
        
//     }
// };