// O(2^n) time and O(n) stack space
// Recursion
// class Solution {
// public:
//     int climbStairs(int n) {
//         if(n <= 1) return 1;
//         int oneStep = climbStairs(n - 1);
//         int twoSteps = climbStairs(n - 2);
//         return oneStep + twoSteps;
//     }
// };

// O(n) time and O(1) stack space
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1) return 1;
        int prev2 = 1;
        int prev1 = 1;
        for(int i=2; i<=n; i++){
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};