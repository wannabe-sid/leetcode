// Recursion -> Memoization (Top Down)
// O(n^3) time and O(n^2) space and O(n) stack space
// class Solution {
// public:
//     int solve(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
//         if(i > j) return 0;
//         if(dp[i][j] != -1) return dp[i][j];
//         int maxCoins = -1e9;
//         for(int k=i; k<=j; k++){
//             int coins = (nums[i-1] * nums[k] * nums[j+1])
//                         + solve(i, k-1, nums, dp)
//                         + solve(k+1, j, nums, dp);
//             maxCoins = max(maxCoins, coins);
//         }
//         return dp[i][j] = maxCoins;
//     }
//     int maxCoins(vector<int>& nums) {
//         int n = nums.size();
//         nums.insert(nums.begin(), 1);
//         nums.insert(nums.end(), 1);
//         vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
//         return solve(1, n, nums, dp);
//     }
// };

// Recursion -> Tabulation (Bottom Up)
// O(n^3) time and O(n^2) space and O(1) stack space
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        for(int i=n; i>=1; i--){
            for(int j=i; j<=n; j++){
                int maxCoins = -1e9;
                for(int k=i; k<=j; k++){
                    int coins = (nums[i-1] * nums[k] * nums[j+1]) + dp[i][k-1] + dp[k+1][j];
                    maxCoins = max(maxCoins, coins);
                }
                dp[i][j] = maxCoins;
            }
        }
        return dp[1][n];
    }
};