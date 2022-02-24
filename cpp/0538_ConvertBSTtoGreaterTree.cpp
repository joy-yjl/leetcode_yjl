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
    int last=0;
    int calSum(TreeNode * root)
    {
        if(root==nullptr)
            return 0;
        int left=calSum(root->left);
        int right=calSum(root->right);
        int sum=left+right+root->val;
        return sum;
    }
    void flush(TreeNode * root,int sum)
    {
        if(root==nullptr)
            return ;
        flush(root->left,sum);
        int tmp=root->val;
        root->val=sum-last;
        last+=tmp;
        flush(root->right,sum);

    }
    TreeNode* convertBST(TreeNode* root) {
        int sum=calSum(root);
        flush(root,sum);
        return root;
    }
};
