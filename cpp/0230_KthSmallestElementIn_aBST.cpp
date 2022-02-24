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
    int val;
    int rank=0;
    void kthSmallest_(TreeNode* root,int k)
    {
        if(root==nullptr)
            return;
        
        kthSmallest_(root->left,k);
        rank++;
        if(k==rank)
        {
            val=root->val;
            return;
        }
        kthSmallest_(root->right,k);

    }
    int kthSmallest(TreeNode* root, int k) {
       kthSmallest_(root,k);
        return val;
        
    }

};
