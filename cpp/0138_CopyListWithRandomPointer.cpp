/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* helper(Node* head,unordered_map<Node*,Node*> & dict)
    {
        if(head==nullptr)
            return nullptr;
        Node * newhead=new Node(head->val);
        dict[head]=newhead;
        newhead->next=helper(head->next,dict);
        return newhead;
    }
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> dict;
        dict[nullptr]=nullptr;
        Node* newhead=helper(head,dict);

        Node* cur=newhead;
        while(head!=nullptr)
        {
            cur->random=dict[head->random];
            head=head->next;
            cur=cur->next;
        }
        return newhead;

        
    }
};
