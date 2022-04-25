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
    vector<int> r;
    int target;
    void helper(TreeNode* root,vector<vector<int>> & res)
    {
        if(root==nullptr)
            return;
        target-=root->val; 
        r.push_back(root->val);
        if(root->left==nullptr && root->right==nullptr && target==0)
            res.push_back(r);
        helper(root->left,res);
        helper(root->right,res);
        target+=root->val;
        r.pop_back();
        return;

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        this->target=targetSum;
        vector<vector<int>> res;
        if(root==nullptr)
            return res;
        helper(root,res);
        return res;
    }
};
