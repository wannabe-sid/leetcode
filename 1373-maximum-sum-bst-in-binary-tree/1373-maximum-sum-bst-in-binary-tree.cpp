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

// O(n) time and O(logn) space
struct SubtreeInfo {
    bool isBST;
    int minVal;
    int maxVal;
    int sum;
};
class Solution {
    int maxSum = 0;
    SubtreeInfo traverse(TreeNode* root) {
        // Base case: an empty tree is a valid BST with sum 0
        if (!root) {
            return {true, INT_MAX, INT_MIN, 0};
        }
        SubtreeInfo left = traverse(root -> left);
        SubtreeInfo right = traverse(root -> right);
        // Check if subtree rooted at 'root' is a valid BST
        if (left.isBST && right.isBST && (root -> val > left.maxVal) && (root -> val < right.minVal)) {
            int currentSum = root -> val + left.sum + right.sum;
            maxSum = max(maxSum, currentSum);
            int currentMin = min(root -> val, left.minVal);
            int currentMax = max(root -> val, right.maxVal);
            return {true, currentMin, currentMax, currentSum};
        }
        // Not a BST: return invalid bounds so ancestor nodes fail BST validation
        return {false, INT_MIN, INT_MAX, 0};
    }
public:
    int maxSumBST(TreeNode* root) {
        maxSum = 0;
        traverse(root);
        return maxSum;
    }
};