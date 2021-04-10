/*
平衡二叉树的判定
*/

//方法1
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
    bool isBalanced(TreeNode* root){
        return getDepth(root) != -1;
    }

    int getDepth(TreeNode* root){
        if (root == nullptr){
            return 0;
        }

        int leftDepth = getDepth(root->left);
        if (leftDepth == -1){
            return -1;
        }
        
        int rightDepth = getDepth(root->right);
        if (rightDepth == -1){
            return -1;
        }

        if (abs(leftDepth - rightDepth) > 1){
            return -1;
        }

        return max(leftDepth,rightDepth) + 1;
    }
};

//方法2
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
    bool isBalanced(TreeNode* root){
        return getDepth(root) != -1;
    }

    int getDepth(TreeNode* root){
        if (root == nullptr){
            return 0;
        }

        int leftDepth = getDepth(root->left);       
        int rightDepth = getDepth(root->right);

        if (leftDepth == -1 || rightDepth == -1 || abs(leftDepth - rightDepth) > 1){
            return -1;
        }

        return max(leftDepth,rightDepth) + 1;
    }
};