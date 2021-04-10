/*
二叉树的层次遍历
*/

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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root){
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int currentLevelSize = q.size();
            res.push_back(vector<int>());
            for (int i = 0; i < currentLevelSize; ++i){
                TreeNode* now = q.front();
                q.pop();
                res.back().push_back(now->val);
                if (now->left != nullptr){
                    q.push(now->left);
                }
                if (now->right != nullptr){
                    q.push(now->right);
                }
            }

        }
        return res;
    }
};