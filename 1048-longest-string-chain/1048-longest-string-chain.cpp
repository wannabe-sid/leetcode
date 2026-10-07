// O(n^2 * L) time and O(n) space and O(1) stack space 
class Solution {
public:
    // Longest String Chain : LeetCode 1048
    // Similar to Largest Increasing Subsequence : Leetcode 300
    // Formulate as Longest String Subsequence
    bool compare(string& s1, string& s2){
        int n = s1.length();
        int m = s2.length();
        if(n != m + 1) return false;
        int i = 0;
        int j = 0;
        while(i < n){
            if(j < m && s1[i] == s2[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        if(i == n && j == m) return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string& word1, string& word2){
            return word1.length() < word2.length();
        });
        int n = words.size();
        vector<int> dp(n, 1);
        int lsc = 1;
        for(int idx=0; idx<n; idx++){
            for(int prevIdx=0; prevIdx<idx; prevIdx++){
                if(compare(words[idx], words[prevIdx]) && dp[idx] < 1 + dp[prevIdx]){
                    dp[idx] = 1 + dp[prevIdx];
                }
            }
            lsc = max(lsc, dp[idx]);
        }
        return lsc;
    }
};