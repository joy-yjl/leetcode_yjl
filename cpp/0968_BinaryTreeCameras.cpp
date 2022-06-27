
// Input: root = [0,0,null,0,0]
// Output: 1
// Explanation: One camera is enough to monitor all nodes if placed as shown.

// Input: root = [0,0,null,0,null,0,null,null,0]
// Output: 2
// Explanation: At least two cameras are needed to monitor all nodes of the tree. 
// The above image shows one of the valid configurations of camera placement.
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
private:
    int res=0;
public:
    //0 - node don't have camera(0) and is not being watched(0) total 0.
    //1 - node don't have camera(0) and is being watched(1) total 1.
    //2 - node has camera(1) and is being watched(1) total 2.
    int helper(TreeNode * root)
    {
        if(root==nullptr)
            return 1;
        int l=helper(root->left);
        int r=helper(root->right);
        if(l==0 || r==0)
        {
            res++;
            return 2;
        }
        if(l==2 || r==2){
            return 1;
        }
        return 0;

    }
    int minCameraCover(TreeNode* root) {
        if(root==nullptr)
            return 0;
        if(root->left==nullptr && root->right==nullptr)
            return 1;
        int status=helper(root);
        return status==0?res+1:res;

    }
};



