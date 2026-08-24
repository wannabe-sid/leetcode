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

// O(n) time and O(n) stack space
class Solution {
public:
    int checkHeight(TreeNode* node){
        if(node == nullptr) return 0;
        int leftHeight = checkHeight(node -> left);
        if(leftHeight == -1) return -1;
        int rightHeight = checkHeight(node -> right);
        if(rightHeight == -1) return -1;
        if(abs(leftHeight - rightHeight) > 1) return -1;
        return 1 + max(leftHeight, rightHeight);
    }
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};