/*
二叉树的先序遍历
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root, res);
        return res;
    }

    void preorder(TreeNode* root, vector<int> &num){
        if (root == nullptr){
            return ;
        }

        num.push_back(root->val);
        preorder(root->left, num);
        preorder(root->right, num);
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr){
            return res;
        }

        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* now = st.top();
            st.pop();
            res.push_back(now->val);
            if (now->right != nullptr){
                st.push(now->right);
            }
            if (now->left != nullptr){
                st.push(now->left);
            }
        }
        return res;
    }
};