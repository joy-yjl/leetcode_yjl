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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr)
            return res;
        stack<TreeNode *> s1;
        stack<TreeNode *> s2;
        s1.push(root);
        
        while(!s1.empty() || !s2.empty())
        {
            vector<int> r;
            if(!s1.empty())
            {
                int m=s1.size();
                for(int i=0;i<m;i++)
                {
                    TreeNode *tmp=s1.top();
                    s1.pop();
                    r.push_back(tmp->val);
                    if(tmp->left!=nullptr)
                        s2.push(tmp->left);
                    if(tmp->right!=nullptr)
                        s2.push(tmp->right);
                }
            }

            else
            {
                int m=s2.size();
                for(int i=0;i<m;i++)
                {
                    TreeNode *tmp=s2.top();
                    s2.pop();
                    r.push_back(tmp->val);
                    if(tmp->right!=nullptr)
                        s1.push(tmp->right);
                    if(tmp->left!=nullptr)
                        s1.push(tmp->left);
                }

            }
            
            res.push_back(r);
        }
        return res;
    }
};
