/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==nullptr)
            return "#";
        string res=to_string(root->val);
        string left=serialize(root->left);
        string right=serialize(root->right);

        return res+","+left+","+right;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout<<data<<endl;
        stack<TreeNode *> s;
        TreeNode * root=nullptr;
        TreeNode * cur=nullptr;
        int vis=0;
        

        for(int i=0;i<data.size();i++)//
        {
            int flag=1;
            
            
            if(data[i]==',')
                continue;
            if(data[i]=='-')
            {
                flag=-1;
                i++;
            }
            
            if(data[i]>='0'&& data[i]<='9')
            {
                int num=0;
                while(data[i]>='0'&& data[i]<='9')
                {
                    num=num*10+data[i]-'0';
                    i++;
                }
                num=flag*num;
                if(root==nullptr)
                {
                    root=new TreeNode(num);
                    cur=root;
                    s.push(cur);
                }
                else
                {
                    if(vis==1)
                    {
                        cur->right=new TreeNode(num);
                        cur=cur->right;

                    }
                    else
                    {
                        cur->left=new TreeNode(num);
                        cur=cur->left;
                    }
                    s.push(cur);

                }
                vis=0;

            }
            else if(data[i]=='#')
            {
                if(root==nullptr)
                    return nullptr;
                if(s.empty())
                    break;
                cur=s.top();
                s.pop();
                if(vis==0)
                    cur->left=nullptr;
                else
                    cur->right=nullptr;
                vis=1;
            }
        }
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==nullptr)
            return "#";
        string res=to_string(root->val);
        string left=serialize(root->left);
        string right=serialize(root->right);

        return res+","+left+","+right;
        
    }

    // Decodes your encoded data to tree.

    TreeNode* deserialize(string data) {
        queue<string> q;
        string s="";
        for(int i=0;i<data.size();i++)
        {
            if(data[i]==',')
            {
                q.push(s);
                s="";
                continue;
            }
            s+=data[i];
        }
        if(s.size()!=0)q.push(s);
        return deserialize_helper(q);
    }

    TreeNode* deserialize_helper(queue<string> &q) {
        string s=q.front();
        q.pop();
        if(s=="#")return nullptr;
        TreeNode* root=new TreeNode(stoi(s));
        root->left=deserialize_helper(q);
        root->right=deserialize_helper(q);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

