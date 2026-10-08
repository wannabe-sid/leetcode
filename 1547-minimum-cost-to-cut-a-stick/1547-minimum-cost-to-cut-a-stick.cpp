// Recusrion -> Memoization (Top Down)
// O(c^3) time and O(c^2) space and O(c) stack space
// class Solution {
// public:
//     int solve(int i, int j, vector<int>& cuts, vector<vector<int>>& dp){
//         if(i > j) return 0;
//         if(dp[i][j] != -1) return dp[i][j];
//         int minCost = 1e9;
//         for(int k=i; k<=j; k++){
//             int cost = (cuts[j+1] - cuts[i-1])
//                        + solve(i, k-1, cuts, dp)
//                        + solve(k+1, j, cuts, dp);
//             minCost = min(minCost, cost);
//         }
//         return dp[i][j] = minCost;
//     }
//     int minCost(int n, vector<int>& cuts) {
//         int c = cuts.size();
//         cuts.insert(cuts.begin(), 0);
//         cuts.insert(cuts.end(), n);
//         sort(cuts.begin(), cuts.end());
//         vector<vector<int>> dp(c+1, vector<int>(c+1, -1));
//         return solve(1, c, cuts, dp);
//     }
// };

// Recusrion -> Tabulation (Bottom Up)
// O(c^3) time and O(c^2) space and O(1) stack space
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.insert(cuts.end(), n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c+2, vector<int>(c+2, 0));
        for(int i=c; i>=1; i--){
            for(int j=i; j<=c; j++){
                int minCost = 1e9;
                for(int k=i; k<=j; k++){
                    int cost = (cuts[j+1] - cuts[i-1]) + dp[i][k-1] + dp[k+1][j];
                    minCost = min(minCost, cost);
                }
                dp[i][j] = minCost;
            }
        }
        return dp[1][c];
    }
};