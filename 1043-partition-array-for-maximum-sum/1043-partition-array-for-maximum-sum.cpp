// Recursion -> Memoization (Top Down)
// O(n^2) time and O(n) space and O(n) stack space
class Solution {
public:
    int solve(int i, int k, vector<int>& arr, vector<int>& dp){
        int n = arr.size();
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        int length = 0;
        int maxNum = -1e9;
        int maxSum = -1e9;
        for(int j=i; j<min(n, i+k); j++){
            length++;
            maxNum = max(maxNum, arr[j]);
            int sum = (length * maxNum) + solve(j+1, k, arr, dp);
            maxSum = max(maxSum, sum);
        }
        return dp[i] = maxSum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(0, k, arr, dp);
    }
};

// Recursion -> Tabulation (Bottom Up)
// O() time and O() space and O() stack space
// class Solution {
// public:
//     int maxSumAfterPartitioning(vector<int>& arr, int k) {
//         int n = arr.size();
//         vector<int> dp(n, -1);
//         return solve(0, k, arr, dp);
//     }
// };