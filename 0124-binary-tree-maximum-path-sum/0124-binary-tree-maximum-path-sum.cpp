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
    int checkPathSum(TreeNode* node, int& maxPathSum){
        if(node == nullptr) return 0;
        int leftPathSum = max(0, checkPathSum(node -> left, maxPathSum));
        int rightPathSum = max(0, checkPathSum(node -> right, maxPathSum));
        maxPathSum = max(maxPathSum, leftPathSum + rightPathSum + node -> val);
        return (node -> val) + max(leftPathSum, rightPathSum);
    }
    int maxPathSum(TreeNode* root) {
        int maxPathSum = INT_MIN;
        checkPathSum(root, maxPathSum);
        return maxPathSum;
    }
};