/*
二叉搜索树的判定
*/

//方法1：二叉搜索树的中序是增序的
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
    void inorder(TreeNode* root, vector<int> &res){
        if (root == nullptr){
            return;
        }

        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }

    bool isValidBST(TreeNode* root) {
        vector<int> res;
        inorder(root, res);     
        for (int i = 1; i < res.size(); ++i){
            if (res[i] <= res[i-1]){
                return false;
            }
        }
        return true;
    }
};

//方法2：迭代实现树的中序
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
    bool isValidBST(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        while(!st.empty() || root != nullptr){
            while(root != nullptr){
                st.push(root);
                root = root->left;
            }

            root = st.top();
            st.pop();
            res.push_back(root->val);
            root = root->right;
        }

        for (int i = 1; i < res.size(); ++i){
            if (res[i] <= res[i-1]){
                return false;
            }
        }
        return true;
    }
};

//方法3：通过保存前个节点，来判断是否增序
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
    bool isValidBST(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* pre = nullptr;
        while(!st.empty() || root != nullptr){
            while(root != nullptr){
                st.push(root);
                root = root->left;
            }

            root = st.top();
            st.pop();

            if (pre != nullptr && pre->val >= root->val){
                return false;
            }

            pre = root;
            root = root->right;
        }

        return true;
    }
};