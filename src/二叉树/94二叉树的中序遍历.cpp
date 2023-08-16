#include <vector>
#include <stack>

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
    vector<int> inorderTraversal(TreeNode* root) {
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
        res.push_back(node->val);
        if (node->right != nullptr)
        {
            traversal(node->right, res);
        }
    }

    vector<int> inorderTraversal2(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        if (root == nullptr) { return res; }

        TreeNode* temp = root;
        bool leftIsNull = false;
        st.push(root);

        while (!st.empty())
        {
            temp = st.top();
            if ((temp->left == nullptr || leftIsNull) && temp->right == nullptr)
            {
                res.push_back(temp->val);
                st.pop();
                if (!st.empty())
                {
                    temp = st.top();
                    res.push_back(temp->val);
                    st.pop();
                    leftIsNull = true;
                    if (temp->right != nullptr)
                    {
                        st.push(temp->right);
                        leftIsNull = false;
                    }
                }
            }
            else if (!(temp->left == nullptr || leftIsNull) && temp->right == nullptr)
            {
                st.push(temp->left);
                leftIsNull = false;
            }
            else if ((temp->left == nullptr || leftIsNull) && !(temp->right == nullptr))
            {
                res.push_back(temp->val);
                st.pop();

                st.push(temp->right);
                leftIsNull = false;
            }
            else
            {
                st.push(temp->left);
                leftIsNull = false;
            }
            

        }
        return res;
    }


};