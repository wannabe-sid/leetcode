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

// O(n) time and O(n) space
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    void buildParent(TreeNode* root, TreeNode* par) {
        if(!root) return;
        parent[root] = par;
        buildParent(root->left, root);
        buildParent(root->right, root);
    }
    TreeNode* findNode(TreeNode* root, int start) {
        if(!root) return nullptr;
        if(root->val == start) return root;
        TreeNode* left = findNode(root->left, start);
        if (left) return left;
        return findNode(root->right, start);
    }
    int amountOfTime(TreeNode* root, int start) {
        buildParent(root, nullptr);
        TreeNode* startNode = findNode(root, start);
        queue<TreeNode*> q;
        unordered_set<TreeNode*> vis;
        q.push(startNode);
        vis.insert(startNode);
        int time = -1;
        while (!q.empty()) {
            int sz = q.size();
            time++;
            while (sz--) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left && !vis.count(curr->left)) {
                    vis.insert(curr->left);
                    q.push(curr->left);
                }
                if (curr->right && !vis.count(curr->right)) {
                    vis.insert(curr->right);
                    q.push(curr->right);
                }
                if (parent[curr] && !vis.count(parent[curr])) {
                    vis.insert(parent[curr]);
                    q.push(parent[curr]);
                }
            }
        }
        return time;
    }
};