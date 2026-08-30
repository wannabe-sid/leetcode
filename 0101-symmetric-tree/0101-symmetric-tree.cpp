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

// PreOrder on left subtree and Reverse PreOrder on right subtree
// O(n) time and O(n) space
class Solution {
public:
    bool helper(TreeNode* left, TreeNode* right){
        if(left == nullptr || right == nullptr) return left == right;
        if(left -> val != right -> val) return false;
        return helper(left -> left, right -> right) && helper(left -> right, right -> left);
    }
    bool isSymmetric(TreeNode* root) {
        return root == nullptr || helper(root -> left, root -> right);
    }
};