// Recursion -> Memoization (Top Down)
// O(n) time and O(n) space O(n) stack space
// class Solution {
// public:
//     int solve(int idx, vector<int>& nums, vector<int>& dp){
//         int n = nums.size();
//         if(idx == 0) return nums[idx];
//         if(idx < 0) return 0;
//         if(dp[idx] != -1) return dp[idx];
//         int take = nums[idx] + solve(idx - 2, nums, dp);
//         int notTake = 0 + solve(idx - 1, nums, dp);
//         return dp[idx] = max(take, notTake);
//     }
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n, -1);
//         return solve(n-1, nums, dp);
//     }
// };

// Recursion -> Tabulation (Bottom Up)
// O(n) time and O(n) space O(1) stack space
// class Solution {
// public:
//     int solve(vector<int>& nums, vector<int>& dp){
//         int n = nums.size();
//         if(n == 0) return 0;
//         if(n == 1) return nums[0];
//         dp[0] = nums[0];
//         dp[1] = max(nums[0], nums[1]);
//         for(int i=2; i<n; i++){
//             int take = nums[i] + dp[i - 2];
//             int notTake = 0 + dp[i - 1];
//             dp[i] = max(take, notTake);
//         }
//         return dp[n - 1];
//     }
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 0) return 0;
//         vector<int> dp(n, -1);
//         return solve(nums, dp);
//     }
// };

// Recursion -> Space Optimizzation
// O(n) time and O(1) space O(1) stack space
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        int prev2 = nums[0];
        int prev = max(nums[0], nums[1]); 
        for(int i=2; i<n; i++){
            int take = nums[i] + prev2;
            int notTake = 0 + prev;
            int curr = max(take, notTake);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};