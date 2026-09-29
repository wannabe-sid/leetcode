// Recursion -> Memoization (Top Down)
// O(n*m) time and O(n*m) space and O(n) stack space
// Time Limit Exceeded
// class Solution {
// public:
//     int solve(int i, int j, int n, int m, vector<vector<int>>& matrix, vector<vector<int>>& dp){
//         if(j < 0 || j >= m) return 1e9;
//         if(i == 0) return matrix[0][j];
//         if(dp[i][j] != -1) return dp[i][j];
//         int up = solve(i-1, j, n, m, matrix, dp);
//         int leftDia = solve(i-1, j-1, n, m, matrix, dp);
//         int rightDia = solve(i-1, j+1, n, m, matrix, dp);
//         return dp[i][j] = matrix[i][j] + min(up, min(leftDia, rightDia));
//     }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int m = matrix[0].size();
//         vector<vector<int>> dp(n, vector<int>(m, -1));
//         int pathSum = 1e9;
//         for(int j=0; j<m; j++){
//             pathSum = min(pathSum, solve(n-1, j, n, m, matrix, dp));
//         }
//         return pathSum;
//     }
// };

// Recursion -> Tabulation (Bottom Up)
// O(n*m) time and O(n*m) space and O(1) stack space
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int j=0; j<m; j++){
            dp[0][j] = matrix[0][j];
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i == 0) continue;
                else{
                    int up = 1e9;
                    int leftDia = 1e9;
                    int rightDia = 1e9;
                    if(i > 0) up = dp[i-1][j];
                    if(i > 0 && j > 0) leftDia = dp[i-1][j-1];
                    if(i > 0 && j < m-1) rightDia = dp[i-1][j+1];
                    dp[i][j] = matrix[i][j] + min(up, min(leftDia, rightDia));
                }
            }
        }
        int pathSum = 1e9;
        for(int j=0; j<m; j++){
            pathSum = min(pathSum, dp[n-1][j]);
        }
        return pathSum;
    }
};

// Recursion -> Space Optimization
// O() time and O() space and O() stack space
// class Solution {
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) {
        
//     }
// };