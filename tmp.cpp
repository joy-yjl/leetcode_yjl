/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
            return head;
        ListNode * cur=new ListNode(-1);
        ListNode *res=head->next;
        ListNode * tmp=nullptr;
       
        
        while(head)
        {
            if(head->next)
            {
                cur->next=head->next;
                tmp=head->next->next;
                cur=cur->next;
            }
            else
                tmp=nullptr;

            cur->next=head;
            cur=cur->next;
            head=tmp;

        }
        cout<<res<<endl;
        return res;
        
    }
};


