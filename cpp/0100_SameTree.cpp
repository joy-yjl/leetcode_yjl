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
    string helper(TreeNode* p,string s)
    {
        if(p==nullptr)
        {
            s=s+"#";
            return s;
        }
        s=s+to_string(p->val);
        string s1=helper(p->left,s);
        string s2=helper(p->right,s);
        string sf=s1+','+s2;
        return sf;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        string s1=helper(p,"");
        string s2=helper(q,"");
        cout<<s1<<endl;
        cout<<s2<<endl;

        if(s1==s2)
            return true;
        else
            return false;
        
    }
};
