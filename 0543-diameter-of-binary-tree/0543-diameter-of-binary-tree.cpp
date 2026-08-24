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
    int checkHeight(TreeNode* node, int& diameter){
        if(node == nullptr) return 0;
        int leftHeight = checkHeight(node -> left, diameter);
        int rightHeight = checkHeight(node -> right, diameter);
        diameter = max(diameter, leftHeight + rightHeight);
        return 1 + max(leftHeight, rightHeight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        checkHeight(root, diameter);
        return diameter;
    }
};