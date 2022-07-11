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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root==nullptr)
            return res;
        queue<TreeNode *> que;
        que.push(root);


        while(!que.empty())
        {
            TreeNode * tmp=nullptr;
            int n=que.size()
            for(int i=0;i<n;i++)
            {
                tmp=que.front();
                que.pop();
                if(i==0)
                    res.push_back(tmp->val);
                if(tmp->right!=nullptr)
                    que.push(tmp->right);
                if(tmp->left!=nullptr)
                    que.push(tmp->left);
                
            }
            
            
        }
        return res;
        
    }
};

