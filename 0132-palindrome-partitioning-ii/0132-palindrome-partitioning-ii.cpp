// Recursion -> Memoization (Top Down)
// O(n^2) time and O(n) space and O(n) stack space
// class Solution {
// public:
//     bool isPalindrome(string& str){
//         int left = 0;
//         int right = str.length() - 1;
//         while(left <= right){
//             if(str[left] != str[right]) return 0;
//             left++;
//             right--;
//         }
//         return 1;
//     }
//     int solve(int i, string& s, vector<int>& dp){
//         int n = s.length();
//         if(i == n) return 0;
//         if(dp[i] != -1) return dp[i];
//         string temp = "";
//         int minCuts = 1e9;
//         for(int j=i; j<n; j++){
//             temp += s[j];
//             if(isPalindrome(temp)){
//                 int cuts = 1 + solve(j+1, s, dp);
//                 minCuts = min(minCuts, cuts);
//             }
//         }
//         return dp[i] = minCuts;
//     }
//     int minCut(string s) {
//         int n = s.length();
//         vector<int> dp(n,-1);
//         return solve(0, s, dp) - 1;
//     }
// };

// Recursion -> Tabulation (Bottom Up)
// O(n^2) time and O(n) space and O(1) stack space
class Solution {
public:
    bool isPalindrome(string& str){
        int left = 0;
        int right = str.length() - 1;
        while(left <= right){
            if(str[left] != str[right]) return 0;
            left++;
            right--;
        }
        return 1;
    }
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n+1, 0);
        for(int i=n-1; i>=0; i--){
            int minCuts = 1e9;
            string temp = "";
            for(int j=i; j<n; j++){
                temp += s[j];
                if(isPalindrome(temp)){
                    int cuts = 1 + dp[j+1];
                    minCuts = min(minCuts, cuts);
                }
            }
            dp[i] = minCuts;
        }
        return dp[0] - 1;
    }
};