/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Recursive
// O(n^2) time and O(n) space
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == nullptr) return {};
        vector<int> left = postorderTraversal(root -> left);
        result.insert(result.end(), left.begin(), left.end());
        vector<int> right = postorderTraversal(root -> right);
        result.insert(result.end(), right.begin(), right.end());
        result.push_back(root -> val);
        return result;
    }
};

// Iterative
// O(n) time and O(n) space
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> result;
//         stack<TreeNode*> st;
//         TreeNode* curr = root;
//         while (curr != nullptr || !st.empty()) {
//             // Reach the leftmost node of the current subtree
//             while (curr != nullptr) {
//                 st.push(curr);
//                 curr = curr->left;
//             }
//             // Current is null here, pop from stack
//             curr = st.top();
//             st.pop();
//             // Visit the node
//             result.push_back(curr->val);
//             // Move to the right subtree
//             curr = curr->right;
//         }
//         return result;
//     }
// };