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

// Approach 1
// O(n) time and O(n) stack space
class Solution {
public:
    TreeNode* prev = nullptr;
    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        flatten(root -> right);
        flatten(root -> left);
        root -> right = prev;
        root -> left = nullptr;
        prev = root;
    }
};

// Approach 2
// O() time and O() space
// class Solution {
// public:
//     void flatten(TreeNode* root) {
        
//     }
// };

// Approach 3
// O() time and O() space
// class Solution {
// public:
//     void flatten(TreeNode* root) {
        
//     }
// };