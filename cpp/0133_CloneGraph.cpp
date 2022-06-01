/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node * helper(Node * node,unordered_map<Node*,Node*> &dict )
    {
        Node * newnode=new Node(node->val);
        vector<Node *> nb;
        dict[node]=newnode;
        int n=node->neighbors.size();
        for(int i=0;i<n;i++)
        {
            if(dict.count(node->neighbors[i])>0)
                nb.push_back(dict[node->neighbors[i]]);
            else
                nb.push_back(helper(node->neighbors[i],dict));
        }
        newnode->neighbors=nb;

        return newnode;
    }
    Node* cloneGraph(Node* node) {
        if(node==nullptr)
            return nullptr;
        if(node->neighbors.size()==0)
        {
            Node * newnode=new Node(node->val);
            return newnode;
        }
        unordered_map<Node*,Node*> dict;
        return helper(node,dict);
        
    }
};
