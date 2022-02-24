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
    int findMax(vector<int> & nums,int left,int right)
    {
        int index=-1;
        int max=INT_MIN;
        for(int i=left;i<=right;i++)
        {
            if(max<nums[i])
            {
                max=nums[i];
                index=i;
            }
        }
        return index;
    }
    TreeNode* buildTree(vector<int> & nums,int left,int right)
    {
        if(right<left)
            return nullptr;
        if(right==left)
        {
            TreeNode * root=new TreeNode(nums[left]);
            return root;
        }
        int max_position=findMax(nums,left,right);
        TreeNode * root=new TreeNode(nums[max_position]);
        root->left=buildTree(nums,left,max_position-1);
        root->right=buildTree(nums,max_position+1,right);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums)
    {
        int max_position=findMax(nums,0,nums.size()-1);
        TreeNode * root=new TreeNode(nums[max_position]);
        root->left=buildTree(nums,0,max_position-1);
        root->right=buildTree(nums,max_position+1,nums.size()-1);
        return root;
        
    }
    
    
};
