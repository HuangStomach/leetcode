/**
 * 965. 单值二叉树
 * 如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。
 * 只有给定的树是单值二叉树时，才返回 true；否则返回 false。
 */
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isUnivalTree(TreeNode *root) {
        if (!root) return true;
        
        if (root->left) {
            if (root->val != root->left->val || !isUnivalTree(root->left)) return false;
        }
        if (root->right) {
            if (root->val != root->right->val || !isUnivalTree(root->right)) return false;
        }
        return true;
    }
};
