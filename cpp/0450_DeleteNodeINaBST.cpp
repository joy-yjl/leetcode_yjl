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
    TreeNode * find(TreeNode * root)
    {
        while(root->left)
            root=root->left;
        return root;

    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr)
            return nullptr;
        if(root->val==key)
        {
            if(root->left==nullptr)
            {
                return root->right;
            }
            if(root->right==nullptr)
            {
                return root->left;
            }

            TreeNode * tmp=find(root->right);
            root->val=tmp->val;
            root->right=deleteNode(root->right,tmp->val);
            return root;


        }
        else if(root->val>key)
            root->left=deleteNode(root->left,key);
        else if(root->val<key)
            root->right=deleteNode(root->right,key);
        
        return root;
    }
};
