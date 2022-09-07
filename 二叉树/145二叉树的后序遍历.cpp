#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }

    void traversal(TreeNode* node, vector<int>& res)
    {
        if (node == nullptr) { return; }
        if (node->left != nullptr)
        {
            traversal(node->left, res);
        }
        if (node->right != nullptr)
        {
            traversal(node->right, res);
        }
        res.push_back(node->val);
    }
};