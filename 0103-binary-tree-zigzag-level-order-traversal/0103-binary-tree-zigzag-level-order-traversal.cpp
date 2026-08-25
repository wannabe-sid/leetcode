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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr) return result;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;      // true for L->R and false for R->L
        while(!q.empty()){
            int size = q.size();
            vector<int> level(size);
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                int idx = (flag) ? i : (size - 1 - i);
                level[idx] = node -> val;
                if(node -> left != nullptr) q.push(node -> left);
                if(node -> right != nullptr) q.push(node -> right);
            }
            flag = !flag;
            result.push_back(level);
        }
        return result;
    }
};