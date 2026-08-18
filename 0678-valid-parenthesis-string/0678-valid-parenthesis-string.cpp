// Approach 1 : Using Recursion
// O(3^n) time and O(n) stack space
// class Solution {
// public:
//     bool solve(string& s, int idx, int count){
//         int n = s.length();
//         if(count < 0) return false;
//         if(idx == n) return count == 0;
//         if(s[idx] == '(') return solve(s, idx + 1, count + 1);
//         if(s[idx] == ')') return solve(s, idx + 1, count - 1);
//         return solve(s, idx + 1, count + 1) || solve(s, idx + 1, count - 1) || solve(s, idx + 1, count);
//     }
//     bool checkValidString(string s) {
//         return solve(s, 0, 0);
//     }
// };

// Approach 2 : Using Greedy
// O(n) time and O(1) space
class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0, maxOpen = 0;
        for (char c : s) {
            if (c == '(') {
                minOpen++;
                maxOpen++;
            } else if (c == ')') {
                minOpen--;
                maxOpen--;
            } else {
                minOpen--;
                maxOpen++;
            }
            if (maxOpen < 0) return false;
            minOpen = max(minOpen, 0);
        }
        return minOpen == 0;
    }
};