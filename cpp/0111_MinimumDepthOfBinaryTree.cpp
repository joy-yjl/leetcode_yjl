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
    int helper(TreeNode * root)
    {
        if(root==nullptr)
            return 0;
        int left=helper(root->left);
        int right=helper(root->right);
        if(left==0) return right+1;
        if(right==0) return left+1;
        return min(right,left)+1;
    }
    int minDepth(TreeNode* root) {
        if(root==nullptr)
            return 0;
        return helper(root);
        
    }
};
