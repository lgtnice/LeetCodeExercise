#include <vector>
#include <stack>

using namespace std;

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
     vector<int> preorderTraversal(TreeNode* root) {
         vector<int> res;
         traversal(root, res);
         return res;
     }

     void traversal(TreeNode* node, vector<int>& res)
     {
         if (node == nullptr) { return; }
         res.push_back(node->val);
         if (node->left != nullptr)
         {
             traversal(node->left, res);
         }
         if (node->right != nullptr)
         {
             traversal(node->right, res);
         }
     }

     //����ջ�������ķ�ʽʵ��
     vector<int> preorderTraversal2(TreeNode* root) {
         vector<int> res;
         if (root != nullptr)
         {
             res.push_back(root->val);
             
             stack<TreeNode*> st;
             if (root->right != nullptr)
             {
                 st.push(root->right);
             }
             if (root->left != nullptr)
             {
                 st.push(root->left);
             }
             while (!st.empty())
             {
                 TreeNode* temp = st.top();
                 //��Ҫ pop�ģ�push��res�ģ�push��st�Ľڵ㣬������ͨ��temp����
                 //����һ���ɺ�
                 st.pop();
                 res.push_back(temp->val);
                 
                 if (temp->right != nullptr)
                 {
                     st.push(temp->right);
                 }
                 if (temp->left != nullptr)
                 {
                     st.push(temp->left);
                 }
             }
         }
         return res;
     }
 };