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

//vector<int> (bool isvalid, int sum ,int max,int min,int max_sum) 

class Solution {
public:
    vector<int> maxSumBST_(TreeNode * root)
    {
        if(root==nullptr)
        {
            vector<int> res={1,0,INT_MIN,INT_MAX,0};
            return res;
        }
        vector<int> left=maxSumBST_(root->left);
        vector<int> right=maxSumBST_(root->right);
        if((root->left==nullptr || root->val>left[2]) && (root->right==nullptr||root->val<right[3]) && left[0] && right[0] )
        {
            int sum=left[1]+right[1]+root->val;
            int max_num=root->right==nullptr?root->val:right[2];
            int min_num=root->left==nullptr?root->val:left[3];

            int maxsum=max(max(left[4],right[4]),sum);

           
            vector<int> res={1,sum,max_num,min_num,maxsum};
            return res;
        }
        else
        {
            int maxsum=max(left[4],right[4]);
            vector<int> res={0,0,0,0,maxsum};
            return res;

        }


    }
    int maxSumBST(TreeNode* root) {
        vector<int> res=maxSumBST_(root);
        return res[4];
        
    }
};
