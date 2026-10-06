// Recursion -> Memoization (Top Down)
// O(n*2*k) time and O(n*2*k) space and O(n) stack space
// class Solution {
// public:
//     int solve(int idx, int buy, int cap, vector<int>& prices,  vector<vector<vector<int>>>& dp){
//         if(cap == 0) return 0;
//         if(idx == prices.size()) return 0;
//         if(dp[idx][buy][cap] != -1) return dp[idx][buy][cap];
//         int profit = 0;
//         if(buy == 1){
//             profit = max((-prices[idx] + solve(idx+1, 0, cap, prices, dp)), // Buy
//                         (0 + solve(idx+1, 1, cap, prices, dp)));            // Not Buy
//         }
//         else{
//             profit = max((prices[idx] + solve(idx+1, 1, cap-1, prices, dp)), // Sell
//                         (0 + solve(idx+1, 0, cap, prices, dp)));           // Not Sell
//         }
//         return dp[idx][buy][cap] = profit;
//     }
//     int maxProfit(int k, vector<int>& prices) {
//         int n = prices.size();
//         // dp[index][buy or not][number of transactions]
//         vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
//         return solve(0, 1, k, prices, dp);
//     }
// };

// Recursion -> Tabulation (Bottom Up)
// O(n*2*k) time and O(n*2*k) space and O(1) stack space
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // dp[index][buy or not][number of transactions]
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        for(int idx=n-1; idx>=0; idx--){
            for(int buy=1; buy>=0; buy--){
                for(int cap=k; cap>=1; cap--){
                    int profit = 0;
                    if(buy == 1){
                        profit = max((-prices[idx] + dp[idx+1][0][cap]), // Buy
                                    (0 + dp[idx+1][1][cap]));            // Not Buy
                    }
                    else{
                        profit = max((prices[idx] + dp[idx+1][1][cap-1]), // Sell
                                    (0 + dp[idx+1][0][cap]));             // Not Sell
                    }
                    dp[idx][buy][cap] = profit;
                }
            }
        }
        return dp[0][1][k];
    }
};

// Recursion -> Space Optimization
// O(n*2*k) time and O(1) space and O(1) stack space
// class Solution {
// public:
//     int maxProfit(int k, vector<int>& prices) {
        
//     }
// };