// Recursion -> Memoization (Top Down)
// O(n*m) time and O(n*m) space and O(n+m) stack space
// class Solution {
// public:
//     int solve(int i, int j, string& word1, string& word2, vector<vector<int>>& dp){
//         if(i == 0) return j;
//         if(j == 0) return i;
//         if(dp[i][j] != -1) return dp[i][j];
//         if(word1[i-1] == word2[j-1]) return dp[i][j] = 0 + solve(i-1, j-1, word1, word2, dp);
//         else return dp[i][j] = min((1 + solve(i, j-1, word1, word2, dp)), // Insert
//                                min((1 + solve(i-1, j, word1, word2, dp)), // Delete
//                                (1 + solve(i-1, j-1, word1, word2, dp)))); // Replace
//     }
//     int minDistance(string word1, string word2) {
//         int n = word1.length();
//         int m = word2.length();
//         vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
//         return solve(n, m, word1, word2, dp);
//     }
// };

// Recursion -> Tabulation (Bottom Up)
// O(n*m) time and O(n*m) space and O(1) stack space
// class Solution {
// public:
//     int minDistance(string word1, string word2) {
//         int n = word1.length();
//         int m = word2.length();
//         vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
//         for(int j=0; j<=m; j++) dp[0][j] = j;
//         for(int i=0; i<=n; i++) dp[i][0] = i;
//         for(int i=1; i<=n; i++){
//             for(int j=1; j<=m; j++){
//                 if(word1[i-1] == word2[j-1]) dp[i][j] = 0 + dp[i-1][j-1];
//                 else dp[i][j] = min((1 + dp[i][j-1]), // Insert
//                                 min((1 + dp[i-1][j]), // Delete
//                                 (1 + dp[i-1][j-1]))); // Replace
//             }
//         }
//         return dp[n][m];
//     }
// };

// Recursion -> Space Optimization
// O(n*m) time and O(2m) space and O(1) stack space
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<int> prev(m+1, 0);
        vector<int> curr(m+1, 0);
        for(int j=0; j<=m; j++) prev[j] = j;
        for(int i=1; i<=n; i++){
            curr[0] = i;
            for(int j=1; j<=m; j++){
                if(word1[i-1] == word2[j-1]) curr[j] = 0 + prev[j-1];
                else curr[j] = min((1 + curr[j-1]), // Insert
                                min((1 + prev[j]), // Delete
                                (1 + prev[j-1]))); // Replace
            }
            prev = curr;
        }
        return prev[m];
    }
};

// Recursion -> More Space Optimization
// O(n*m) time and O(m) space and O(1) stack space
// class Solution {
// public:
//     int minDistance(string word1, string word2) {
        
//     }
// };