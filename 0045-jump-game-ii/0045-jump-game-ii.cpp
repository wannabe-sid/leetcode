// Approach 1 : Using Recursion
// O(n^n) time and O(n) space
// class Solution {
// public:
//     int solve(vector<int>& nums, int idx, int jumps){
//         if(idx >= nums.size() - 1) return jumps;
//         int mini = INT_MAX;
//         for(int i=1; i<=nums[idx]; i++){
//             mini = min(mini, solve(nums, idx + i, jumps + 1));
//         }
//         return mini;
//     }
//     int jump(vector<int>& nums) {
//         return solve(nums, 0, 0);
//     }
// };

// Approach 2 : Using Recursion + DP
// O(n^2) time and O(n) space
// class Solution {
// public:
//     int solve(vector<int>& nums, int idx, vector<int>& dp) {
//         if (idx >= nums.size() - 1) return 0;   
//         if (dp[idx] != -1) return dp[idx];       
//         int mini = 1e9;        
//         for (int i = 1; i <= nums[idx]; i++) {
//             if (idx + i < nums.size()) {
//                 mini = min(mini, 1 + solve(nums, idx + i, dp));
//             }
//         }        
//         return dp[idx] = mini;
//     }
//     int jump(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n, -1);
//         return solve(nums, 0, dp);
//     }
// };

// Approach 3 : Using Greedy Method
// O(n) time and O(1) space
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int jumps = 0;
        while(right < n - 1){
            int farthest = 0;
            for(int idx=left; idx<=right; idx++){
                farthest = max(farthest, idx + nums[idx]);
            }
            left = right + 1;
            right = farthest;
            jumps++;
        }
        return jumps;
    }
};