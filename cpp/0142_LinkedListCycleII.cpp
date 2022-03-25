/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* res=nullptr;
        if(head==nullptr||head->next==nullptr)
            return res;
        ListNode * cur=head;
        ListNode * fast=head;
        while(fast!=nullptr)
        {
            cur=cur->next;
            fast=fast->next;
            if(fast!=nullptr)
                fast=fast->next;
            if(cur==fast)
            {
                break;
            }
        }
        if(fast==nullptr)
            return res;
        cur=head;
        while(cur!=fast)
        {
            cur=cur->next;
            fast=fast->next;

        }
        res=cur;
        return res;
        
    }
};


