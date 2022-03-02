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
    int maxsum=INT_MIN;
    int maxPathSum_(TreeNode * root)
    {
        if(root==nullptr)
            return 0;
        int left=max(maxPathSum_(root->left),0);
        int right=max(maxPathSum_(root->right),0);
        int sum=left+right+root->val;
        maxsum=maxsum>sum?maxsum:sum;
        return max(left,right)+root->val;

    }
    int maxPathSum(TreeNode* root) {
        int sum=maxPathSum_(root);
        return maxsum;
    }
};

