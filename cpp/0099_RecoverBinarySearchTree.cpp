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
    TreeNode * s=nullptr;
    TreeNode * t=nullptr;
    TreeNode * pre=nullptr;
    void recoverTree_(TreeNode * root)
    {
        if(root==nullptr)
            return ;
        recoverTree_(root->left);
        if(pre!=nullptr && pre->val > root->val)
        {
            if(s==nullptr)
                s=pre;
            t=root;
            
        }
        pre=root;
        recoverTree_(root->right);
    }
    void recoverTree(TreeNode* root) {
        recoverTree_(root);
        int tmp=s->val;
        s->val=t->val;
        t->val=tmp;
    }
};
