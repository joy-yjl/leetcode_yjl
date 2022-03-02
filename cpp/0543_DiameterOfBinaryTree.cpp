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
    int maxdiameter=0;
    int maxDepth(TreeNode * root)
    {
        if(root== nullptr)
            return 0;

        int left=maxDepth(root->left);
        int right=maxDepth(root->right);
        maxdiameter=max(left+right,maxdiameter);
        return max(left,right)+1;

    }
    int diameterOfBinaryTree(TreeNode * root)
    {
        maxDepth(root);
        return maxdiameter;
    }
};