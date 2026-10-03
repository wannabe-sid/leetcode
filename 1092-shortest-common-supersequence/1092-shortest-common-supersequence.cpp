// Take the lcs just once and rest of the characters as they are
// e.g: s1 = brute, s2 = groot, lcs = rt
// So take rt once and bue, goo as it is
// Which then becomes bgruoote with a length of 8 (5 + 5 - 2)
// So the length of supersequence = len(s1) + len(s2) - len(lcs)

// Recursion -> Tabulation (Bottom Up)
// O(n*m) time and O(n*m) space and O(1) stack space
class Solution {
public:
    // Print Longest Common Subsequence Code (Modified)
    // O(n*m) time and O(n+m) space and O(1) stack space
    string longestCommonSubsequence(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=0; i<=n; i++) dp[i][0] = 0;
        for(int j=0; j<=m; j++) dp[0][j] = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);
            }
        }
        string ans = "";
        int i = n;
        int j = m;
        while(i > 0 && j > 0){
            if(s1[i-1] == s2[j-1]){
                ans += s1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                ans += s1[i-1];
                i--;
            }
            else{
                ans += s2[j-1];
                j--;
            }
        }
        while(i > 0){
            ans += s1[i-1];
            i--;
        }
        while(j > 0){
            ans += s2[j-1];
            j--;
        }
        return ans;
    }
    // Print Shortest Common SuperSequence Code
    string shortestCommonSupersequence(string str1, string str2) {
        string scs = longestCommonSubsequence(str1, str2);
        reverse(scs.begin(), scs.end());
        return scs;
    }
};

