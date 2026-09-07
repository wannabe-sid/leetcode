// BruteForce
// class Solution {
// public:
//     void solve(int idx, string& current, string& s, int n, unordered_set<string>& result) {
//         if (idx == n) {
//             result.insert(current);
//             return;
//         }
//         // Pick
//         current.push_back(s[idx]);
//         solve(idx + 1, current, s, n, result);
//         // Don't pick
//         current.pop_back();
//         solve(idx + 1, current, s, n, result);
//     }
//     int distinctSubseqII(string s) {
//         string current = "";
//         unordered_set<string> result;
//         int n = s.length();
//         solve(0, current, s, n, result);
//         // Exclude the empty string
//         return result.size() - 1; 
//     }
// };

// Optimal
class Solution {
public:
    int distinctSubseqII(string s) {
        long long MOD = 1e9 + 7;
        int total = 0;
        int dp[26] = {0};
        for(char& c : s){
            int idx = c - 'a';
            int newSub = (total + 1 - dp[idx] + MOD) % MOD;
            total = (total + newSub) % MOD;
            dp[idx] = (dp[idx] + newSub) % MOD;
        }
        return total;
    }
};