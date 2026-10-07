// O(n^2) time and O(2n) space and O(1) stack space
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> count(n, 1);
        int maxLen = 0;
        for(int idx=0; idx<n; idx++){
            for(int prevIdx=0; prevIdx<idx; prevIdx++){
                if(nums[idx] > nums[prevIdx] && dp[idx] < 1 + dp[prevIdx]){
                    dp[idx] = 1 + dp[prevIdx];
                    count[idx] = count[prevIdx];
                }
                else if(nums[idx] > nums[prevIdx] && dp[idx] == 1 + dp[prevIdx]){
                    count[idx] += count[prevIdx];
                } 
            }
            maxLen = max(maxLen, dp[idx]);
        }
        int numOfLIS = 0;
        for(int i=0; i<n; i++){
            if(dp[i] == maxLen) numOfLIS += count[i];
        }
        return numOfLIS;
    }
};