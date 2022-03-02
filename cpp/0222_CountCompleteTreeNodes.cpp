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
    int countNodes(TreeNode* root) {
        TreeNode * cur=root;
        int left=0,right=0;
        while(cur!=nullptr)
        {
            cur=cur->left;
            left++;
        }
        cur=root;
        while(cur!=nullptr)
        {
            cur=cur->right;
            right++;
        }
        if(left==right)
            return pow(2,left)-1;
        else
            return countNodes(root->left)+countNodes(root->right)+1;

        
    }
};
