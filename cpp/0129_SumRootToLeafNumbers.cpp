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
    int res=0;
    void helper(TreeNode * root, int num)
    {
        if(root->left==nullptr && root->right==nullptr)
        {
            num=num*10+root->val;
            res+=num;
            return;
        }
        num=num*10+root->val;
        if(root->left!=nullptr)
            helper(root->left,num);
        if(root->right!=nullptr)
            helper(root->right,num);
        return;
    }
    int sumNumbers(TreeNode* root) {
        helper(root,0);
        return res;

    }
};
