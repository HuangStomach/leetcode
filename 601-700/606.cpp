/** 
 * 606. 根据二叉树创建字符串
 * 你需要采用前序遍历的方式，将一个二叉树转换成一个由括号和整数组成的字符串。
 * 空节点则用一对空括号 "()" 表示。而且你需要省略所有不影响字符串与原始二叉树之间的一对一映射关系的空括号对。
 */
#include <string>

using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    string res;
    string tree2str(TreeNode *t) {
        if (t != nullptr) str(t);
        return res;
    }

    void str(TreeNode *node) {
        if (node == nullptr) return;
        res.append(to_string(node->val));

        if (node->left != nullptr) {
            res.push_back('(');
            str(node->left);
            res.push_back(')');
        }
        
        if (node->right != nullptr) {
            if (node->left == nullptr) {
                res.push_back('(');
                res.push_back(')');
            }
            res.push_back('(');
            str(node->right);
            res.push_back(')');
        }
    }
};