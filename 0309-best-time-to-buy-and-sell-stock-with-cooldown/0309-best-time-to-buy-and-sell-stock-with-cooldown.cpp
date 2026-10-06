// Recursion -> Memoization (Top Down)
// O(n) time and O(n) space and O(n) stack space
// class Solution {
// public:
//     int solve(int idx, int buy, vector<int>& prices, vector<vector<int>>& dp){
//         if(idx >= prices.size()) return 0;
//         if(dp[idx][buy] != -1) return dp[idx][buy];
//         int profit = 0;
//         if(buy == 1){
//             profit = max((-prices[idx] + solve(idx+1, 0, prices, dp)), // Buy
//                         (0 + solve(idx+1, 1, prices, dp)));            // Not Buy
//         }
//         else{
//             profit = max((prices[idx] + solve(idx+2, 1, prices, dp)), // Sell
//                         (0 + solve(idx+1, 0, prices, dp)));           // Not Sell
//         }
//         return dp[idx][buy] = profit;
//     }
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         // dp[index][buy or not];
//         // index from 0 to n-1 and buy indicates whether you can buy or not
//         vector<vector<int>> dp(n, vector<int>(2, -1));
//         return solve(0, 1, prices, dp);
//     }
// };

// Recursion -> Tabulation (Bottom Up)
// O(n) time and O(n) space and O(1) stack space
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // dp[index][buy or not];
        // index from 0 to n-1 and buy indicates whether you can buy or not
        vector<vector<int>> dp(n+2, vector<int>(2, 0));
        for(int idx=n-1; idx>=0; idx--){
            for(int buy=1; buy>=0; buy--){
                int profit = 0;
                if(buy == 1){
                    profit = max((-prices[idx] + dp[idx+1][0]), // Buy
                                (0 + dp[idx+1][1]));            // Not Buy
                }
                else{
                    profit = max((prices[idx] + dp[idx+2][1]), // Sell
                                (0 + dp[idx+1][0]));           // Not Sell
                }
                dp[idx][buy] = profit;
            }
        }
        return dp[0][1];
    }
};

// Recursion -> Space Optimization
// O(n) time and O(1) space and O(1) stack space
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<int> next(2, 0);
//         for(int idx=n-1; idx>=0; idx--){
//             for(int buy=1; buy>=0; buy--){
//                 int profit = 0;
//                 if(buy == 1){
//                     profit = max((-prices[idx] + next[0]), // Buy
//                                 (0 + next[1]));            // Not Buy
//                 }
//                 else{
//                     profit = max((prices[idx] + next[1]), // Sell
//                                 (0 + next[0]));           // Not Sell
//                 }
//                 next[buy] = profit;
//             }
//         }
//         return next[1];
//     }
// };
