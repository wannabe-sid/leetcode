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

// O(n*h) time and O(n) space
class Solution {
public:
    void dfs(TreeNode* node, string currentPath, vector<string>& result) {
        if(!node) return;
        // Append current node's value
        if (!currentPath.empty()) currentPath += "->";
        currentPath += to_string(node->val);
        // If it's a leaf node, record the path
        if (!node->left && !node->right) {
            result.push_back(currentPath);
            return;
        }
        // Traverse left and right subtrees
        if(node->left) dfs(node->left, currentPath, result);
        if(node->right) dfs(node->right, currentPath, result);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if(!root) return result;
        dfs(root, "", result);
        return result;
    }
};