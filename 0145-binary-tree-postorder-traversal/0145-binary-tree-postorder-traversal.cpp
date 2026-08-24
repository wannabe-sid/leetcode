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
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> result;
//         if(root == nullptr) return {};
//         vector<int> left = postorderTraversal(root -> left);
//         result.insert(result.end(), left.begin(), left.end());
//         vector<int> right = postorderTraversal(root -> right);
//         result.insert(result.end(), right.begin(), right.end());
//         result.push_back(root -> val);
//         return result;
//     }
// };

// Iterative
// O(n) time and O(n) space
// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> result;
//         stack<TreeNode*> st;
//         TreeNode* curr = root;
//         TreeNode* lastVisited = nullptr;
//         while (curr != nullptr || !st.empty()) {
//             // Reach the leftmost node of the current subtree
//             while (curr != nullptr) {
//                 st.push(curr);
//                 curr = curr->left;
//             }
//             TreeNode* peekNode = st.top();
//             // If right child exists and traversing from the left child, move right
//             if (peekNode->right != nullptr && lastVisited != peekNode->right) {
//                 curr = peekNode->right;
//             } else {
//                 // Visit the node
//                 result.push_back(peekNode->val);
//                 lastVisited = peekNode;
//                 st.pop();
//             }
//         }
//         return result;
//     }
// };

// Using Two Stacks
// O(n) time and O(n) space
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == nullptr) return result;
        stack<TreeNode*> st1, st2;
        st1.push(root);
        while(!st1.empty()){
            root = st1.top();
            st1.pop();
            st2.push(root);
            if(root -> left != nullptr) st1.push(root -> left);
            if(root -> right != nullptr) st1.push(root -> right);
        }
        while(!st2.empty()){
            result.push_back(st2.top() -> val);
            st2.pop();
        }
        return result;
    }
};