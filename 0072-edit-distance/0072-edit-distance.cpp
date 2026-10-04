// Recursion -> Memoization (Top Down)
// O(n*m) time and O(n*m) space and O(n+m) stack space
class Solution {
public:
    int solve(int i, int j, string& word1, string& word2, vector<vector<int>>& dp){
        if(i == 0) return j;
        if(j == 0) return i;
        if(dp[i][j] != -1) return dp[i][j];
        if(word1[i-1] == word2[j-1]) return dp[i][j] = 0 + solve(i-1, j-1, word1, word2, dp);
        else return dp[i][j] = min((1 + solve(i, j-1, word1, word2, dp)), // Insert
                               min((1 + solve(i-1, j, word1, word2, dp)), // Delete
                               (1 + solve(i-1, j-1, word1, word2, dp)))); // Replace
    }
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(n, m, word1, word2, dp);
    }
};

// Recursion -> Tabulation (Bottom Up)
// O(n*m) time and O(n*m) space and O(1) stack space
// class Solution {
// public:
//     int minDistance(string word1, string word2) {
        
//     }
// };

// Recursion -> Space Optimization
// O(n*m) time and O(2m) space and O(1) stack space
// class Solution {
// public:
//     int minDistance(string word1, string word2) {
        
//     }
// };

// Recursion -> More Space Optimization
// O(n*m) time and O(m) space and O(1) stack space
// class Solution {
// public:
//     int minDistance(string word1, string word2) {
        
//     }
// };