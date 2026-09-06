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

// O(n) time and O(1) space
class Solution {
private:
    TreeNode* prev;
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
private:
    void inorder(TreeNode* root){
        if(root == nullptr) return;
        inorder(root -> left);
        if(prev != nullptr && (root -> val < prev -> val)){
            if(first == nullptr){
                first = prev;
                middle = root;
            }
            else last = root;
        }
        prev = root;
        inorder(root -> right);
    }
public:
    void recoverTree(TreeNode* root) {
        prev = first = middle = last = nullptr;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last) swap(first -> val, last -> val);
        else if(first && middle) swap(first -> val, middle -> val);
    }
};