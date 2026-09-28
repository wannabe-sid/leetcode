// Recursion -> Memoization (Top Down)
// O(n*m) time and O(n*m) space and O(n+m) stack space
// class Solution {
// public:
//     int solve(int i, int j, int n, int m, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){
//         if(i >= 0 && j >= 0 && obstacleGrid[i][j] == 1) return 0;
//         if(i == 0 && j == 0) return 1;
//         if(i < 0 || j < 0) return 0;
//         if(dp[i][j] != -1) return dp[i][j];
//         int left = solve(i, j-1, n, m, obstacleGrid, dp);
//         int up = solve(i-1, j, n, m, obstacleGrid, dp);
//         return dp[i][j] = left + up;
//     }
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int n = obstacleGrid.size();
//         int m = obstacleGrid[0].size();
//         vector<vector<int>> dp(n, vector<int>(m, -1));
//         return solve(n-1, m-1, n, m, obstacleGrid, dp);
//     }
// };

// Recursion -> Tabulation (Bottom Up)
// O(n*m) time and O(n*m) space and O(1) stack space
// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int n = obstacleGrid.size();
//         int m = obstacleGrid[0].size();
//         vector<vector<int>> dp(n, vector<int>(m, -1));\
//         dp[0][0] = 1;
//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
//                 else if(i == 0 && j == 0) continue;
//                 else{
//                     int left = 0;
//                     int up = 0;
//                     if(j > 0) left = dp[i][j-1];
//                     if(i > 0) up = dp[i-1][j];
//                     dp[i][j] = left + up;
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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<int> prevRow(m, 0);
        for(int i=0; i<n; i++){
            vector<int> currRow(m, 0);
            for(int j=0; j<m; j++){
                if(obstacleGrid[i][j] == 1) prevRow[j] = 0;
                else if(i == 0 && j == 0) currRow[j] = 1;
                else{
                    int left = 0;
                    int up = 0;
                    if(j > 0) left = currRow[j-1];
                    if(i > 0) up = prevRow[j];
                    currRow[j] = left + up;
                }
            }
            prevRow = currRow;
        }
        return prevRow[m-1];
    }
};