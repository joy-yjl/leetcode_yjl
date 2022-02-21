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
    void preorderTraversal_(TreeNode* root,vector<int> &res)
    {
        if(root== nullptr)
            return;
        res.push_back(root->val);
        preorderTraversal_(root->left,res);
        preorderTraversal_(root->right,res);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorderTraversal_(root,res);
        return res;

    }
    
};

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
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> res;
        if(root== nullptr)
            return res;
        stack<TreeNode *> s;
        TreeNode * cur=root;
        while(!s.empty()||cur!=nullptr)
        {
            while(cur)
            {
                s.push(cur);
                res.push_back(cur->val);
                cur=cur->left;
            }
            if(!s.empty())
            {
                cur=s.top();
                s.pop();
                cur=cur->right;
            }
        }
        return res;
    }
    
};
