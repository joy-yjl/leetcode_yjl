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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr)
            return res;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> r;
            int m=q.size();
            for(int i=0;i<m;i++)
            {
                TreeNode *tmp=q.front();
                q.pop();
                r.push_back(tmp->val);
                if(tmp->left!=nullptr)
                    q.push(tmp->left);
                if(tmp->right!=nullptr)
                    q.push(tmp->right);

            }
            res.push_back(r);
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};
