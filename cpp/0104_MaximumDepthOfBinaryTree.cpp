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
    int maxDepth(TreeNode* root) {
        if(root== nullptr)
            return 0;
        int res=max(maxDepth(root->left),maxDepth(root->right))+1;
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
    int res=0,depth=0;
    void maxDepth_(TreeNode *root)
    {
        if(root==nullptr)
        {
            res=max(res,depth);
            return;
        }
        depth++;
        maxDepth_(root->left);
        maxDepth_(root->right);
        depth--;

    }
    int maxDepth(TreeNode * root)
    {
        maxDepth_(root);
        return res;

    }
    
};
