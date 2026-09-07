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

class Solution {
public:
    int distinctSubseqII(string s) {
        long long MOD = 1e9 + 7;
        // lastCount[i] stores the new distinct subsequences added 
        // the last time character ('a' + i) was processed.
        vector<long long> lastCount(26, 0);
        // current_distinct tracks the total number of non-empty distinct subsequences so far
        long long current_distinct = 0;
        for (char c : s) {
            int idx = c - 'a';
            // New subsequences created by appending 'c':
            // 1 (character 'c' by itself) + all existing subsequences with 'c' appended
            long long new_added = (current_distinct + 1) % MOD;
            // Update total: add new additions, subtract duplicates (what this char added previously)
            current_distinct = (current_distinct + new_added - lastCount[idx] + MOD) % MOD;
            // Store what this char added at this step
            lastCount[idx] = new_added;
        }
        return current_distinct;
    }
};