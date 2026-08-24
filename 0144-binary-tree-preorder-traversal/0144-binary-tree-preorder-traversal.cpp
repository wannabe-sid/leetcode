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
// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> result;
//         if(root == nullptr) return {};
//         result.push_back(root -> val);
//         vector<int> left = preorderTraversal(root -> left);
//         result.insert(result.end(), left.begin(), left.end());
//         vector<int> right = preorderTraversal(root -> right);
//         result.insert(result.end(), right.begin(), right.end());
//         return result;
//     }
// };

// Iterative
// O(n) time and O(n) space
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == nullptr) return result;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();
            result.push_back(curr->val);
            // Push right first so left is popped and processed first
            if (curr->right != nullptr) st.push(curr->right);
            if (curr->left != nullptr) st.push(curr->left);
        }
        return result;
    }
};