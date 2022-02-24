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
    TreeNode * buildTree_(vector<int> & preorder,int preleft,int preright,vector<int> &inorder,int inleft,int inright)
    {
        if(inleft==inright)
        {
            TreeNode * root=new TreeNode(inorder[inleft]);
            return root;
        }
        if(inleft>inright)
            return nullptr;
        TreeNode * root=new TreeNode(preorder[preleft]);
        int index=findIndex(inorder,inleft,inright,preorder[preleft]);
        root->left=buildTree_(preorder,preleft+1,preleft+index-inleft,inorder,inleft,index-1);
        root->right=buildTree_(preorder,preleft+index-inleft+1,preright,inorder,index+1,inright);
        return root;



    }
    TreeNode * buildTree(vector<int> & preorder,vector<int> &inorder)
    {
        if(preorder.size()!=inorder.size()||preorder.size()==0)
            return nullptr;
        TreeNode * root=new TreeNode(preorder[0]);
        int index=findIndex(inorder,0,inorder.size()-1,preorder[0]);
        root->left=buildTree_(preorder,1,index,inorder,0,index-1);
        root->right=buildTree_(preorder,index+1,preorder.size()-1,inorder,index+1,inorder.size()-1);
        return root;

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
    int preInd=0;
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return createTree(preorder,inorder,0,inorder.size() - 1);
    }
    TreeNode* createTree(vector<int>& preorder, vector<int>& inorder,int start, int end){
        if(start > end){
            return NULL;
        }
        TreeNode* node=new TreeNode(preorder[preInd++]);
        int pos;
        for(int i=start;i<=end;i++){
            if(inorder[i]==node->val){
                pos=i;
                break;
            }
        }
        node->left =createTree(preorder, inorder,start,pos-1);
        node->right =createTree(preorder, inorder, pos+1,end);
        return node;
    }
};
