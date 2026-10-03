// Recursion -> Memoization (Top Down)
// O(n1*n2) time and O(n1*n2) space and O(n1+n2) stack space
// class Solution {
// public:
//     int solve(int idx1, int idx2, string& text1, string& text2, vector<vector<int>>& dp){
//         if(idx1 < 0 || idx2 < 0) return 0;
//         if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
//         if(text1[idx1] == text2[idx2]) return dp[idx1][idx2] = 1 + solve(idx1-1, idx2-1, text1, text2, dp);
//         return dp[idx1][idx2] = 0 + max(solve(idx1-1, idx2, text1, text2, dp), solve(idx1, idx2-1, text1, text2, dp));
//     }
//     int longestCommonSubsequence(string text1, string text2) {
//         int n1 = text1.length();
//         int n2 = text2.length();
//         vector<vector<int>> dp(n1, vector<int>(n2, -1));
//         return solve(n1-1, n2-1, text1, text2, dp);
//     }
// };

// Recursion -> Tabulation (Bottom Up)
// O(n1*n2) time and O(n1*n2) space and O(1) stack space
// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int n1 = text1.length();
//         int n2 = text2.length();
//         vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
//         for(int i=0; i<=n1; i++) dp[i][0] = 0;
//         for(int j=0; j<=n2; j++) dp[0][j] = 0;
//         for(int i=1; i<=n1; i++){
//             for(int j=1; j<=n2; j++){
//                 if(text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
//                 else dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);
//             }
//         }
//         return dp[n1][n2];
//     }
// };

// Recursion -> Space Optimization
// O(n1*n2) time and O(n1+n2) space and O(1) stack space
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        vector<int> prev(n2+1, 0);
        vector<int> curr(n2+1, 0);
        for(int j=0; j<=n2; j++) prev[j] = 0;
        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                if(text1[i-1] == text2[j-1]) curr[j] = 1 + prev[j-1];
                else curr[j] = 0 + max(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        return prev[n2];
    }
};