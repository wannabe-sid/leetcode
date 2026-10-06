// Recursion -> Memoization (Top Down)
// O(n^2) time and O(n^2) space and O(n) stack space
// class Solution {
// public:
//     int solve(int idx, int prevIdx, vector<int>& nums, vector<vector<int>>& dp){
//         if(idx == nums.size()) return 0;
//         if(dp[idx][prevIdx+1] != -1) return dp[idx][prevIdx+1];
//         int notTake = 0 + solve(idx+1, prevIdx, nums, dp);
//         int take = 0;
//         if(prevIdx == -1 || nums[idx] > nums[prevIdx]) take = 1 + solve(idx+1, idx, nums, dp);
//         return dp[idx][prevIdx+1] = max(take, notTake);
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         // dp[index][previous index];
//         vector<vector<int>> dp(n, vector<int>(n+1, -1));
//         return solve(0, -1, nums, dp);
//     }
// };

// Recursion -> Tabulation (Bottom Up)
// O(n^2) time and O(n^2) space and O(1) stack space
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         // dp[index][previous index];
//         vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
//         for(int prevIdx=0; prevIdx<=n; prevIdx++) dp[n][prevIdx] = 0;
//         for(int idx=n-1; idx>=0; idx--){
//             for(int prevIdx=idx-1; prevIdx>=-1; prevIdx--){
//                 int notTake = 0 + dp[idx+1][prevIdx+1];
//                 int take = 0;
//                 if(prevIdx == -1 || nums[idx] > nums[prevIdx]) take = 1 + dp[idx+1][idx+1];
//                 dp[idx][prevIdx+1] = max(take, notTake);
//             }
//         }
//         return dp[0][0];
//     }
// };

// Recursion -> Space Optimization
// O(n^2) time and O(2n) space and O(1) stack space
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         // dp[index][previous index];
//         vector<int> next(n+1, 0);
//         vector<int> curr(n+1, 0);
//         for(int prevIdx=0; prevIdx<=n; prevIdx++) next[prevIdx] = 0;
//         for(int idx=n-1; idx>=0; idx--){
//             for(int prevIdx=idx-1; prevIdx>=-1; prevIdx--){
//                 int notTake = 0 + next[prevIdx+1];
//                 int take = 0;
//                 if(prevIdx == -1 || nums[idx] > nums[prevIdx]) take = 1 + next[idx+1];
//                 curr[prevIdx+1] = max(take, notTake);
//             }
//             next = curr;
//         }
//         return next[0];
//     }
// };

// Optimal Solution
// O(n^2) time and O(n) space and O(1) stack space
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for(int idx=0; idx<n; idx++){
            for(int prevIdx=0; prevIdx<=idx-1; prevIdx++){
                if(nums[idx] > nums[prevIdx]){
                    dp[idx] = max(dp[idx], 1+dp[prevIdx]);
                }
            }
        }
        int lis = dp[0];
        for(int i=1; i<n; i++){
            lis = max(lis, dp[i]);
        }
        return lis;
    }
};