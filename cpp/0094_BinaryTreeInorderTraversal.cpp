/*:*
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
    void inorderTraversal_(TreeNode* root,vector<int> &res)
    {
        if(root== nullptr)
            return;
        inorderTraversal_(root->left,res);
        res.push_back(root->val);
        inorderTraversal_(root->right,res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorderTraversal_(root,res);
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
    vector<int> inorderTraversal(TreeNode* root)
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
                cur=cur->left;
            }
            if(!s.empty())
            {
                cur=s.top();
                s.pop();
                res.push_back(cur->val);
                cur=cur->right;
            }
        }
        return res;

    }
};
