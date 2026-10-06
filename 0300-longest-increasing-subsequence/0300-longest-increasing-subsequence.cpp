// Recursion -> Memoization (Top Down)
// O(n^2) time and O(n^2) space and O(n) stack space
class Solution {
public:
    int solve(int idx, int prevIdx, vector<int>& nums, vector<vector<int>>& dp){
        if(idx == nums.size()) return 0;
        if(dp[idx][prevIdx+1] != -1) return dp[idx][prevIdx+1];
        int notTake = 0 + solve(idx+1, prevIdx, nums, dp);
        int take = 0;
        if(prevIdx == -1 || nums[idx] > nums[prevIdx]) take = 1 + solve(idx+1, idx, nums, dp);
        return dp[idx][prevIdx+1] = max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // dp[index][previous index];
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(0, -1, nums, dp);
    }
};

// Recursion -> Tabulation (Bottom Up)
// O() time and O() space and O() stack space
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
        
//     }
// };

// Recursion -> Space Optimization
// O() time and O() space and O() stack space
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
        
//     }
// };