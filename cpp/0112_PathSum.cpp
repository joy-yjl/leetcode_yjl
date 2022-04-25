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
    bool res=false;
    int target;
    void helper(TreeNode* root)
    {
        if(root==nullptr)
            return;
        target-=root->val; 
        if(root->left==nullptr && root->right==nullptr && target==0)
            res=true;
        helper(root->left);
        helper(root->right);
        target+=root->val;
        return;

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        this->target=targetSum;
        if(root==nullptr)
            return false;
        helper(root);
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
    bool helper(TreeNode* root,int target)
    {
        if(root==nullptr)
            return false;
        if(root->left==nullptr && root->right==nullptr && target==root->val)
            return true;

        return helper(root->left,target-root->val) || helper(root->right,target-root->val);

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==nullptr)
            return false;
        bool res=helper(root,targetSum);
        return res;
        
    }
};
