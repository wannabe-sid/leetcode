// Recursion -> Memoization (Top Down)
// O(n^2) time and O(n^2) space and O(2n) stack space
// Time Limit Exceeded
// class Solution { 
// public:
//     int solve(int i, int j, int n, vector<vector<int>>& triangle, vector<vector<int>>& dp){
//         if(i == n - 1) return triangle[n-1][j];
//         if(dp[i][j] != -1) return dp[i][j];
//         int down = triangle[i][j] + solve(i+1, j, n, triangle, dp);
//         int diagonal = triangle[i][j] + solve(i+1, j+1, n, triangle, dp);
//         return dp[i][j] = min(down, diagonal);
//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n = triangle.size();
//         vector<vector<int>> dp(n, vector<int>(n, -1));
//         return solve(0, 0, n, triangle, dp);
//     }
// };

// Recursion -> Tabulation (Bottom Up)
// O(n^2) time and O(n^2) space and O(1) stack space
class Solution { 
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for(int j=0; j<n; j++){
            dp[n-1][j] = triangle[n-1][j];
        }
        for(int i=n-2; i>=0; i--){
            for(int j=i; j>=0; j--){
                if(j == n-1) continue;
                else{
                    int down = triangle[i][j] + dp[i+1][j];
                    int diagonal = triangle[i][j] + dp[i+1][j+1];
                    dp[i][j] = min(down, diagonal);
                }
            }
        }
        return dp[0][0];
    }
};

// Recursion -> Space Optimization
// O() time and O() space and O() stack space
// class Solution { 
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
        
//     }
// };