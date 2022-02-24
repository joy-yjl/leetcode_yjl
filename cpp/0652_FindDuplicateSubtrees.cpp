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
    // string serialize(TreeNode * root)
    // {
    //     if(root==nullptr)
    //         return "#";
    //     string left=serialize(root->left);
    //     string right=serialize(root->right);
    //     string res=left+','+right+to_string(root->val)+',';
    //     return res;
    // }
    string findDuplicateSubtrees_(TreeNode * root,map<string,bool> & flag, map<string,TreeNode *> &res)
    {
        if(root==nullptr)
            return "#";
        string left =findDuplicateSubtrees_(root->left,flag,res);
        string right =findDuplicateSubtrees_(root->right,flag,res);
        string s=left+','+right+to_string(root->val)+',';
        // string s=serialize(root);
        if(flag.count(s))
        {
            flag[s]=true;
        }
        else
        {
            flag[s]=false;
            res[s]=root;
        }
        return s;

    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {

        map<string,bool>  flag_map;
        map<string,TreeNode *> res_map;
        vector<TreeNode*> res;
        findDuplicateSubtrees_(root,flag_map,res_map);
        for(auto iter=flag_map.begin();iter!=flag_map.end();iter++)
        {
            if(iter->second)
            {
                res.push_back(res_map[iter->first]);
            }

        }
        return res;

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

    string findDuplicateSubtrees_(TreeNode * root,map<string,int> & flag, vector<TreeNode *> &res)
    {
        if(root==nullptr)
            return "#";
        string left =findDuplicateSubtrees_(root->left,flag,res);
        string right =findDuplicateSubtrees_(root->right,flag,res);
        string s=left+','+right+to_string(root->val)+',';
        // string s=serialize(root);
        
        if(flag.count(s)==0)
        {
            flag[s]=1;
            
        }
        else if(flag[s]==1)
        {
            flag[s]++;
            res.push_back(root);
        }
        return s;

    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {

        map<string,int>  flag_map;
        vector<TreeNode*> res;
        findDuplicateSubtrees_(root,flag_map,res);
        return res;

    }

        
};
