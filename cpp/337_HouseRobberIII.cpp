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
    vector<int> helper(TreeNode * root)
    {
        if(root==nullptr)
            return {0,0};
        vector<int> left=helper(root->left);
        vector<int> right=helper(root->right);

        int rob=root->val+left[1]+right[1];
        int no_rob=max(left[0],left[1])+max(right[0],right[1]);
        return{rob,no_rob};
    }

    int rob(TreeNode* root) {
        vector<int> res=helper(root);
        return max(res[0],res[1]);
        
    }
};
