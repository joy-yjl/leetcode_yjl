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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorderTraversal_(root,res);
        return res;

    }
    void postorderTraversal_(TreeNode* root,vector<int> &res)
    {
        if(root== nullptr)
            return;
        postorderTraversal_(root->left,res);
        postorderTraversal_(root->right,res);
        res.push_back(root->val);
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
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> res;
        if(root== nullptr)
            return res;
        stack<TreeNode *> s;
        TreeNode * cur=root;
        TreeNode * last;
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
                if(cur->right== nullptr || cur->right==last)
                {
                    res.push_back(cur->val);
                    last=cur;
                    s.pop();
                    cur= nullptr;
                }
                else
                {
                    cur=cur->right;
                }
            }

        }
        return res;

    }

};
