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
    ListNode* partition(ListNode* head, int x) {
        ListNode * newhead=new ListNode(-1,nullptr);
        ListNode * cur=head,*pre=head;
        ListNode * left=newhead, *right=nullptr;
        while(cur!=nullptr)
        {
            if(cur->val < x)
            {
                left->next=cur;
                left=left->next;
                if(cur->next!=nullptr)
                    pre->next=cur->next;
                cur=cur->next;
            }
            else
            {
                pre->next=cur;
                if(right==nullptr)
                    right=cur;
                pre=cur;
                cur=cur->next;

            }

        }
        left->next=right;
        return newhead->next;

        
    }
};
