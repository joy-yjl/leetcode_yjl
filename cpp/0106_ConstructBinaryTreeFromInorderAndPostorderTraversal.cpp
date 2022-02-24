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
    int findIndex(vector<int> & nums,int left,int right,int target)
    {
        int index=-1;
        for(int i=left;i<=right;i++)
        {
            if(target==nums[i])
                return i;
        }
        return index;
    }
    TreeNode * buildTree_(vector<int> & inorder,int inleft,int inright,vector<int> &postorder,int postleft,int postright)
    {
        if(inleft==inright)
        {
            TreeNode * root=new TreeNode(inorder[inleft]);
            return root;
        }
        if(inleft>inright)
            return nullptr;
        TreeNode * root=new TreeNode(postorder[postright]);
        int index=findIndex(inorder,inleft,inright,postorder[postright]);
        root->left=buildTree_(inorder,inleft,index-1,postorder,postleft,postleft+index-inleft-1);
        root->right=buildTree_(inorder,index+1,inright,postorder,postleft+index-inleft,postright-1);
        return root;



    }
    TreeNode * buildTree(vector<int> & inorder,vector<int> &postorder)
    {
        if(postorder.size()!=inorder.size()||postorder.size()==0)
            return nullptr;
        TreeNode * root=new TreeNode(postorder[postorder.size()-1]);
        int index=findIndex(inorder,0,inorder.size()-1,postorder[postorder.size()-1]);
        root->left=buildTree_(inorder,0,index-1,postorder,0,index-1);
        root->right=buildTree_(inorder,index+1,inorder.size()-1,postorder,index,inorder.size()-2);
        return root;

    }
};
