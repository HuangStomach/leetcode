/**
 * 993. 二叉树的堂兄弟节点
 * 在二叉树中，根节点位于深度 0 处，每个深度为 k 的节点的子节点位于深度 k+1 处。
 * 如果二叉树的两个节点深度相同，但 父节点不同 ，则它们是一对堂兄弟节点。
 * 我们给出了具有唯一值的二叉树的根节点 root ，以及树中两个不同节点的值 x 和 y 。
 * 只有与值 x 和 y 对应的节点是堂兄弟节点时，才返回 true 。否则，返回 false。
 */
#include <queue>

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
    bool isCousins(TreeNode *root, int x, int y) {
        TreeNode *xf = nullptr, *yf = nullptr, *cur = nullptr;
        queue<TreeNode *> q;

        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                cur = q.front();
                if (cur->left) {
                    q.push(cur->left);
                    xf = cur->left->val == x ? cur : xf;
                    yf = cur->left->val == y ? cur : yf;
                }
                if (cur->right) {
                    q.push(cur->right);
                    xf = cur->right->val == x ? cur : xf;
                    yf = cur->right->val == y ? cur : yf;
                }
                q.pop();
            }
            if (xf && yf && (xf != yf)) return true;
            if (xf || yf) return false;
        }

        return false;
    }
};
