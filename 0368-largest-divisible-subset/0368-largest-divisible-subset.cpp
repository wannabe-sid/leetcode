// O(n^2) time and O(2n) space and O(1) stack space
class Solution {
public:
    // Largest Divisible Subset : LeetCode 368
    // Similar to Largest Increasing Subsequence : Leetcode 300
    // Formulate as Largest Divisible Subsequence
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> hash(n);
        int maxLen = 1;
        int lastIdx = 0;
        for(int idx=0; idx<n; idx++){
            hash[idx] = idx;
            for(int prevIdx=0; prevIdx<idx; prevIdx++){
                if((nums[idx] % nums[prevIdx] == 0) && (dp[idx] < dp[prevIdx] + 1)){
                    dp[idx] = dp[prevIdx] + 1;
                    hash[idx] = prevIdx;
                }
            }
            if(dp[idx] > maxLen){
                maxLen = dp[idx];
                lastIdx = idx;
            }
        }
        vector<int> result;
        result.push_back(nums[lastIdx]);
        while(hash[lastIdx] != lastIdx){
            lastIdx = hash[lastIdx];
            result.push_back(nums[lastIdx]);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};