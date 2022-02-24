/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void connectNode(Node * left,Node* right)
    {
        if(left== nullptr||right== nullptr)
            return;
        left->next=right;
        connectNode(left->left,left->right);
        connectNode(left->right,right->left);
        connectNode(right->left,right->right);
        
    }
    Node * connect(Node * root)
    {
        if (root == nullptr) return nullptr;
        connectNode(root->left,root->right);
        return root;
    }
};


class Solution {
public:

    Node * connect(Node * root)
    {
        if(root==nullptr) return nullptr;
        queue<Node *> q;
        Node * cur=root;
        q.push(root);
       
        while(!q.empty())
        {
            int size=q.size();
            cur=q.front();
            q.pop();
            Node* last=cur;
            if(cur->left!=nullptr)
                q.push(cur->left);
            if(cur->right!=nullptr)
                q.push(cur->right);
            

            for(int i=1;i<size;i++)
            {
                cur=q.front();
                q.pop();
                last->next=cur;
                last=cur;
                if(cur->left!=nullptr)
                    q.push(cur->left);
                if(cur->right!=nullptr)
                    q.push(cur->right);

            }
            cur->next=nullptr;
            
        }
        return root;
        
    }
};

