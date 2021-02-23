//先序遍历

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans;
    bool bfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if (root == nullptr){
            return false;
        }
        bool lson = bfs(root->left, p , q);
        bool rson = bfs(root->right, p ,q);
        if ( (lson && rson) || ((root->val == p->val || root->val == q->val) && (lson || rson)) ){
            ans = root;
        }

        return lson || rson || (root->val == p->val || root->val == q->val);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bfs(root, p, q);
        return ans;
    }
};

//先序遍历-判断方式2

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root->val == p->val || root->val == q->val){
            return root;
        }     

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left == nullptr && right == nullptr){
            return nullptr;
        }
        if (left == nullptr){
            return right;
        }
        if (right == nullptr){
            return left;
        }

        return root;

    }
};

//层次遍历
//思路是记录节点对应的父节点，然后从要判断的节点开始往根节点推，、
//第一遍推记录访问的路线节点，第二遍推判断节点是否为访问过
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<int, TreeNode*> fa;
    unordered_map<int, bool> vis;
    void dfs(TreeNode* root){
        if (root->left != nullptr){
            fa[root->left->val] = root;
            dfs(root->left);
        }
        if (root->right != nullptr){
            fa[root->right->val] = root;
            dfs(root->right);
        }     
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        fa[root->val] = nullptr;
        dfs(root);
        while(p != nullptr){
            vis[p->val] = true;
            p = fa[p->val];
        }

        while(q != nullptr){
            if (vis[q->val]){
                return q;
            }
            q = fa[q->val];
        }
        return nullptr;
    }
};