/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// O(n) time and O(n) space
class Solution {
public:
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentTrack, TreeNode* target){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr -> left){
                parentTrack[curr -> left] = curr;
                q.push(curr -> left);
            }
            if(curr -> right){
                parentTrack[curr -> right] = curr;
                q.push(curr -> right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentTrack;
        markParents(root, parentTrack, target);
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int currLevel = 0;
        while(!q.empty()){
            int size = q.size();
            if(currLevel++ == k) break;
            for(int i=0; i<size; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr -> left && !visited[curr -> left]){
                    q.push(curr -> left);
                    visited[curr -> left] = true;
                }
                if(curr -> right && !visited[curr -> right]){
                    q.push(curr -> right);
                    visited[curr -> right] = true;
                }
                if(parentTrack[curr] && !visited[parentTrack[curr]]){
                    q.push(parentTrack[curr]);
                    visited[parentTrack[curr]] = true;
                }
            }
        }
        vector<int> result;
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            result.push_back(curr -> val);
        }
        return result;
    }
};