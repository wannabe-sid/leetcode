// Recursion -> Memoization (Top Down)
// O(n*amount) time and O(n*amount) space and O(amount) stack space
// class Solution {
// public:
//     int solve(int idx, int amount, vector<int>& coins, vector<vector<int>>& dp){
//         if(idx == 0) return (amount % coins[0] == 0);
//         if(dp[idx][amount] != -1) return dp[idx][amount];
//         int notTake = solve(idx-1, amount, coins, dp);
//         int take = 0;
//         if(coins[idx] <= amount) take = solve(idx, amount-coins[idx], coins, dp);
//         return dp[idx][amount] = take + notTake;
//     }
//     int change(int amount, vector<int>& coins) {
//         int n = coins.size();
//         vector<vector<int>> dp(n, vector<int>(amount+1, -1));
//         return solve(n-1, amount, coins, dp);
//     }
// };

// Recursion -> Tabulation (Bottom Up)
// O(n*amount) time and O(n*amount) space and O(1) stack space
// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         int n = coins.size();
//         vector<vector<unsigned int>> dp(n, vector<unsigned int>(amount+1, 0));
//         for(int i=0; i<=amount; i++){
//             if(i % coins[0] == 0) dp[0][i] = 1;
//             else dp[0][i] = 0;
//         }
//         for(int i=1; i<n; i++){
//             for(int j=0; j<=amount; j++){
//                 unsigned int notTake = dp[i-1][j];
//                 unsigned int take = 0;
//                 if(coins[i] <= j) take = dp[i][j-coins[i]];
//                 dp[i][j] = take + notTake;
//             }
//         }
//         return (int)dp[n-1][amount];
//     }
// };

// Recursion -> Space Optimization 
// O(n*amount) time and O(2*amount) space and O(1) stack space
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> prev(amount+1, 0);
        vector<int> curr(amount+1, 0);
        for(int i=0; i<=amount; i++){
            if(i % coins[0] == 0) prev[i] = 1;
            else prev[i] = 0;
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<=amount; j++){
                unsigned int notTake = prev[j];
                unsigned int take = 0;
                if(coins[i] <= j) take = curr[j-coins[i]];
                curr[j] = take + notTake;
            }
            prev = curr;
        }
        return prev[amount];
    }
};