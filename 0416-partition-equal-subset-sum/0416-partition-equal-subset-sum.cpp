// O(n*target) time and O(target) space
class Solution {
public:
    // Subset Sum Problem
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<bool> prevRow(sum+1, false);
        vector<bool> currRow(sum+1, false);
        prevRow[0] = true;
        currRow[0] = true;
        if(arr[0] <= sum) prevRow[arr[0]] = true;
        for(int idx=1; idx<n; idx++){
            for(int j=1; j<=sum; j++){
                bool notTake = prevRow[j];
                bool take = false;
                if(j >= arr[idx]){
                    take = prevRow[j - arr[idx]];   
                }
                currRow[j] = take || notTake;
            }
            prevRow = currRow;
        }
        return prevRow[sum];
    }
    // Partition Equal Subset Sum
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int i=0; i<n; i++) totalSum += nums[i];
        if(totalSum % 2 != 0) return false;
        int target = totalSum / 2;
        if(isSubsetSum(nums, target)) return true;
        return false;
    }
};