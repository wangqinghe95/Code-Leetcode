/*
二叉搜索树的删除
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
    //找比root大的最小值
    int FindMin(TreeNode* root) {
        while (root->left != nullptr){
            root = root->left;
        } 
        return root->val;
    }
    //找比root小的最大值
    int FindMax(TreeNode* root) {
        while (root->right != nullptr){
            root = root->right;
        } 
        return root->val;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* p;
        if (root == nullptr){
            return nullptr;
        }

        if (root->val > key){
            root->left = deleteNode(root->left, key);
        }
        else if (root->val < key){
            root->right = deleteNode(root->right, key);
        }
        else{
            if (root->left == nullptr && root->right == nullptr){
                root = nullptr;
            }
            else if (root->right != nullptr){
                root->val = FindMin(root->right);
                root->right = deleteNode(root->right, root->val);
            }
            else{
                root->val = FindMax(root->left);
                root->left = deleteNode(root->left, root->val);
            }
        }
        return root;
    }
};