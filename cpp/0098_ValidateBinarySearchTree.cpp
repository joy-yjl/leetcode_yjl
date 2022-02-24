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
    bool isValidBST_(TreeNode* root,TreeNode *max,TreeNode* min)
    {
        if(root==nullptr)
            return true;
        if(min!=nullptr && root->val <= min->val ) return false;
        if(max!=nullptr && root->val >= max->val ) return false;
        return (isValidBST_(root->left,root,min) && isValidBST_(root->right,max,root));
       
    }
    bool isValidBST(TreeNode* root) {
        
        bool flag=isValidBST_(root,nullptr,nullptr);
        return flag;

        
    }
};
