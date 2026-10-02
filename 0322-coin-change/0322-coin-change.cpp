// Recursion -> Memoization (Top Down)
// O(n*amount) time and O(n*amount) space and O(amount) stack space
// class Solution {
// public:
//     int solve(int idx, vector<int>& coins, int amount, vector<vector<int>>& dp){
//         if(amount == 0) return 0;
//         if (idx == 0) {
//             if (amount % coins[0] == 0) return amount / coins[0];
//             return 1e9;
//         }
//         if(dp[idx][amount] != -1) return dp[idx][amount];
//         int notTake = 0 + solve(idx-1, coins, amount, dp);
//         int take = 1e9;
//         if(amount >= coins[idx]) take = 1 + solve(idx, coins, amount-coins[idx], dp);
//         return dp[idx][amount] = min(take, notTake); 
//     }
//     int coinChange(vector<int>& coins, int amount) {
//         int n = coins.size();
//         vector<vector<int>> dp(n, vector<int>(amount+1, -1));
//         int ans = solve(n-1, coins, amount, dp);
//         return (ans >= 1e9) ? -1 : ans; 
//     }
// };

// Recursion -> Tabulation (Bottom Up)
// O(n*amount) time and O(n*amount) space and O(1) stack space
// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         int n = coins.size();
//         vector<vector<int>> dp(n, vector<int>(amount+1, 0));
//         for(int i=0; i<=amount; i++){
//             if(i % coins[0] == 0) dp[0][i] = i / coins[0];
//             else dp[0][i] = 1e9;
//         }
//         for(int i=1; i<n; i++){
//             for(int j=0; j<=amount; j++){
//                 int notTake = 0 + dp[i-1][j];
//                 int take = 1e9;
//                 if(j >= coins[i]) take = 1 + dp[i][j-coins[i]];
//                 dp[i][j] = min(take, notTake); 
//             }
//         }
//         return (dp[n-1][amount] == 1e9) ? -1 : dp[n-1][amount];
//     }
// };

// Recursion -> Space Optimization 
// O(n*amount) time and O(2*amount) space and O(1) stack space
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount+1, 0);
        vector<int> curr(amount+1, 0);
        for(int i=0; i<=amount; i++){
            if(i % coins[0] == 0) prev[i] = i / coins[0];
            else prev[i] = 1e9;
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<=amount; j++){
                int notTake = 0 + prev[j];
                int take = 1e9;
                if(j >= coins[i]) take = 1 + curr[j-coins[i]];
                curr[j] = min(take, notTake); 
            }
            prev = curr;
        }
        return (prev[amount] == 1e9) ? -1 : prev[amount];
    }
};