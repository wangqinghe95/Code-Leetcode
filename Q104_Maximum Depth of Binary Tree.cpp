//递归写法1

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root){
    if(root == NULL)
    {
        return 0;
    }

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return left > right ? left + 1 : right + 1;
}

//递归写法2
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

//迭代写法
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }
        queue<TreeNode*> Q;
        Q.push(root);
        int ans = 0;
        while (!Q.empty()){
            int sz = Q.size();
            while(sz > 0){
                TreeNode* node = Q.front();
                Q.pop();
                if (node->left != nullptr){
                    Q.push(node->left);
                }
                if (node->right != nullptr){
                    Q.push(node->right);
                }
                sz -= 1;
            }
            ans += 1;
        }
        return ans;
    }
};