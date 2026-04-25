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
std::string dfs2(TreeNode* node, std::vector<TreeNode*>& output_vector, std::unordered_map<std::string, int>& count_subnodes) {
    if (node == nullptr)
        return "#";
    auto left = dfs2(node->left, output_vector, count_subnodes);
    auto right = dfs2(node->right, output_vector, count_subnodes);

    std::string output = std::to_string(node->val) + ',' + left + right;
    if (count_subnodes.find(output) == count_subnodes.end())
        count_subnodes[output] = 0;
    else {
        if (count_subnodes[output] == 0)
            output_vector.push_back(node);
        count_subnodes[output]++;
    }
    return output;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        std::vector<TreeNode*> output_vector {};
        std::unordered_map<std::string, int> count_subnodes{};
        dfs2(root, output_vector, count_subnodes);
        return output_vector;
    }
};