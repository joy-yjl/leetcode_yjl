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
    TreeNode * buildTree_(vector<int> & preorder,int preleft,int preright,vector<int> &postorder,int postleft,int postright)
    {
        if(preleft==preright)
        {
            TreeNode * root=new TreeNode(preorder[preleft]);
            return root;
        }
        if(preleft>preright)
            return nullptr;
        TreeNode * root=new TreeNode(preorder[preleft]);
        
        int index=findIndex(postorder,postleft,postright,preorder[preleft+1]);
        root->left=buildTree_(preorder,preleft+1,preleft+index-postleft+1,postorder,postleft,index);
        root->right=buildTree_(preorder,preleft+index-postleft+2,preright,postorder,index+1,postright-1);
        return root;
        
        



    }
    TreeNode * constructFromPrePost(vector<int> & preorder,vector<int> &postorder)
    {
        if(postorder.size()!=preorder.size()||postorder.size()==0)
            return nullptr;
        if(postorder.size()==1)
        {
            TreeNode * root=new TreeNode(preorder[0]);
            return root;
        }
        TreeNode * root=new TreeNode(preorder[0]);
        int index=findIndex(postorder,0,postorder.size()-1,preorder[1]);
        root->left=buildTree_(preorder,1,index+1,postorder,0,index);
        root->right=buildTree_(preorder,index+2,preorder.size()-1,postorder,index+1,postorder.size()-2);
        return root;

    }
    
};
