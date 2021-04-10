/*
二叉树的后续遍历
*/

//递归
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postOrder(root, res);
        return res;
    }

    void postOrder(TreeNode* root, vector<int> &num){
        if (root == nullptr){
            return;
        }

        postOrder(root->left, num);
        postOrder(root->right, num);
        num.push_back(root->val);
    }
};

//迭代

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr){
            return res;
        }

        stack<TreeNode*> stk1;
        stack<TreeNode*> stk2;

        stk1.push(root);
        while(!stk1.empty()){
            TreeNode* now = stk1.top();
            stk1.pop();
            stk2.push(now);

            if (now->left != nullptr){
                stk1.push(now->left);
            }
            if (now->right != nullptr){
                stk1.push(now->right);
            }
        }

        while(!stk2.empty()){
            TreeNode* now = stk2.top();
            stk2.pop();
            res.push_back(now->val);
        }

        return res;
    }
};