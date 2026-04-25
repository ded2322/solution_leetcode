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
    bool dfs3(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr)
            return true;
        else if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr))
            return false;

        bool left = dfs3(p->left, q->left);
        bool right = dfs3(p->right, q->right);

        return (p->val == q->val) && (left && right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs3(p, q);
    }
};