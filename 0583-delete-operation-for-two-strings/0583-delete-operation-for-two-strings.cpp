// Delete Operations for two strings = len(s1) + len(s2) - 2*len(lcs)
// Recursion -> Space Optimization
// O(n1*n2) time and O(2*n2) space and O(1) stack space
class Solution {
public:
    // Longest Common Subsequence
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        vector<int> prev(n2+1, 0);
        vector<int> curr(n2+1, 0);
        for(int j=0; j<=n2; j++) prev[j] = 0;
        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                if(text1[i-1] == text2[j-1]) curr[j] = 1 + prev[j-1];
                else curr[j] = 0 + max(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        return prev[n2];
    }
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        int lcs = longestCommonSubsequence(word1, word2);
        return n + m - 2 * lcs;
    }
};