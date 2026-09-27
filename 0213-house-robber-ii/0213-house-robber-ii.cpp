// Recursion -> Space Optimizzation
// O(n) time and O(2n) space O(1) stack space
class Solution {
public:
    // Leetcode 198 : House Robber I
    int solve(vector<int>& nums) {
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
    // Leetcode 213 : House Robber II
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> temp1, temp2;
        for(int i=0; i<n; i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n - 1) temp2.push_back(nums[i]);
        }
        return max(solve(temp1), solve(temp2));
    }
};