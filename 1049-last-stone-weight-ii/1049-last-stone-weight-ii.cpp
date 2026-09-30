// O(n*totalSum) time and O(n*totalSum) space
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int totalSum = 0;
        for(int i=0; i<n; i++) totalSum += stones[i];
        // Subset Sum Problem
        vector<vector<bool>> dp(n+1, vector<bool>(totalSum+1, false));
        for(int i=0; i<n; i++){
            dp[i][0] = true;
        }
        if(stones[0] <= totalSum) dp[0][stones[0]] = true;
        for(int idx=1; idx<n; idx++){
            for(int j=1; j<=totalSum; j++){
                bool notTake = dp[idx-1][j];
                bool take = false;
                if(j >= stones[idx]){
                    take = dp[idx-1][j - stones[idx]];   
                }
                dp[idx][j] = take || notTake;
            }
        }
        // Last Stone Weight II
        int minSum = INT_MAX;
        for(int s1=0; s1<=totalSum/2; s1++){
            if(dp[n-1][s1] == true){
                int sum1 = s1;
                int sum2 = totalSum - sum1;
                minSum = min(minSum, abs(sum2 - sum1));
            }
        }
        return minSum;
    }
};