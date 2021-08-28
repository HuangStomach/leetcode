/**
 * 872. 叶子相似的树
 * 请考虑一棵二叉树上所有的叶子，这些叶子的值按从左到右的顺序排列形成一个 叶值序列 。
 * 如果有两棵二叉树的叶值序列是相同，那么我们就认为它们是 叶相似 的。
 * 如果给定的两个根结点分别为 root1 和 root2 的树是叶相似的，则返回 true；否则返回 false 。 
 */
#include <vector>

using namespace std;

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
    void dfs(TreeNode *node, vector<int> &seq) {
        if (!node->left && !node->right) seq.push_back(node->val);
        
        else {
            if (node->left) dfs(node->left, seq);
            if (node->right) dfs(node->right, seq);
        }
    }

    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        vector<int> seq1;
        if (root1) dfs(root1, seq1);

        vector<int> seq2;
        if (root2) dfs(root2, seq2);

        return seq1 == seq2;
    }
};
