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
    bool hasCycle(ListNode *head) {
        bool res=false;
        if(head==nullptr||head->next==nullptr)
            return false;
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
                res=true;
                break;
            }
        }
        return res;
    }
};
