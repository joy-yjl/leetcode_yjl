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
    vector<TreeNode*> build(int left,int right)
    {
        vector<TreeNode *> res;
        if(left>right)
        {
            res.push_back(nullptr);
            return res;
        }
        
        for(int i=left;i<=right;i++)
        {
            vector<TreeNode *> leftTree=build(left,i-1);
            vector<TreeNode *> rightTree=build(i+1,right);
            for(int l=0;l<leftTree.size();l++)
            {
                for(int r=0;r<rightTree.size();r++)
                {
                    TreeNode* root=new TreeNode(i);
                    root->left=leftTree[l];
                    root->right=rightTree[r];
                    res.push_back(root);
                }
            }
        }
        return res;


    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode *> res;
        if(n==0) return res;
        return build(1,n);
        
    }
};
