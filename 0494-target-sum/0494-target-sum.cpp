// Recursion -> Memoization (Top Down)
// O(n*target) time and O(target) space and O(1) stack space
class Solution {
public:
    // sum1 - sum2 = diff
    // (totalSum - sum2) - sum2 = diff
    // totalSum - diff = 2 * sum2
    // sum2 = (totalSum - diff) / 2
    // O(n*target) time and O(target) space and O(1) stack space
    // Count Subsets with sum = target
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> prev(target+1, 0);
        vector<int> curr(target+1, 0);
        if (arr[0] == 0) {
            prev[0] = 2; 
        } else {
            prev[0] = 1; 
            if (arr[0] <= target) {
                prev[arr[0]] = 1; 
            }
        }
        for(int idx=1; idx<n; idx++){
            for(int sum=0; sum<=target; sum++){
                int notTake = prev[sum];
                int take = 0;
                if(arr[idx] <= sum) take = prev[sum - arr[idx]];
                curr[sum] = take + notTake;
            }
            prev = curr;
        }
        return prev[target];
    }
    // Count Subsets with sum = (totalSum - diff) / 2
    int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size();
        int totalSum = 0;
        for(int i=0; i<n; i++) totalSum += arr[i];
        if(totalSum - diff < 0 || (totalSum - diff) % 2) return false;
        return perfectSum(arr, (totalSum - diff) / 2);
    }
    // Target Sum
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums, target);
    }
};