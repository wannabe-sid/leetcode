// Recursion -> Memoization (Top Down)
// O(m*n) time and O(m*n) space and O(m+n) stack space
// class Solution {
// public:
//     int solve(int i, int j, int m, int n, vector<vector<int>>& dp){
//         if(i == m - 1 && j == n - 1) return 1;
//         if(i >= m || j >= n) return 0;
//         if(dp[i][j] != -1) return dp[i][j];
//         int right = solve(i, j + 1, m, n, dp);
//         int down = solve(i + 1, j, m, n, dp);
//         return dp[i][j] = right + down;
//     }
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m, vector<int>(n, -1));
//         return solve(0, 0, m, n, dp);
//     }
// };

// Recursion -> Tabulation (Bottom Up)
// O(m*n) time and O(m*n) space and O(1) stack space
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        dp[m-1][n-1] = 1;
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){          
                if(i == m-1 && j == n-1) continue;
                int right = (j < n-1) ? dp[i][j+1] : 0;
                int down = (i < m-1) ? dp[i+1][j] : 0;
                dp[i][j] = right + down;
            }
        }
        return dp[0][0];
    }
};

// Recursion -> Space Optimization
// O(m*n) time and O(1) space
// class Solution {
// public:
//     int solve(int i, int j, int m, int n, vector<vector<int>>& dp){
//         if(i == m - 1 && j == n - 1) return 1;
//         if(i >= m || j >= n) return 0;
//         if(dp[i][j] != -1) return dp[i][j];
//         int right = solve(i, j+1, m, n, dp);
//         int down = solve(i+1, j, m, n, dp);
//         return dp[i][j] = right + down;
//     }
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m, vector<int>(n, -1));
//         return solve(0, 0, m, n, dp);
//     }
// };