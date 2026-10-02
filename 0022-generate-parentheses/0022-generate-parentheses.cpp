// Approach 1 (Optimal)
// O(4^n) time and O(n^2) stack space
// Only add open parenthesis if open < n
// Only add closing parenthesis if closed < open
// Valid iff open == closed == n

class Solution {
public:
    void backtrack(string curr, int open, int close, int n, vector<string>& res) {
        if (curr.length() == 2 * n) {
            res.push_back(curr);
            return;
        }
        if (open < n) backtrack(curr + '(', open + 1, close, n, res);
        if (close < open) backtrack(curr + ')', open, close + 1, n, res);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack("", 0, 0, n, res);
        return res;

    }
};



// Approach 2 (Not Optimal)
// O(2^2n * n) time and O(n^2) stack space
// class Solution {
// public:
//     bool isValid(string& curr){
//         stack<char> st;
//         for(int i=0; i<curr.length(); i++){
//             if(curr[i] == '(') st.push('(');
//             else{
//                 // Prevent pop on empty stack
//                 if (st.empty()) return false;
//                 st.pop();
//             }
//         }
//         return st.empty();
//     }
//     void solve(string curr, int n, vector<string>& result){
//         if(curr.length() == 2 * n){
//             if(isValid(curr)) result.push_back(curr);
//             return;
//         }
//         // First try with open bracket
//         curr.push_back('(');
//         solve(curr, n, result);
//         curr.pop_back();
//         // Next try with close bracket
//         curr.push_back(')');
//         solve(curr, n, result);
//         curr.pop_back();
//     }
//     vector<string> generateParenthesis(int n) {
//         string curr = "";
//         vector<string> result;
//         solve(curr, n, result);
//         return result;
//     }
// };