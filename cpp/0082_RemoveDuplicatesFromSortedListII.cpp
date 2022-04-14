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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dumpy=new ListNode(-1);
        ListNode *cur=dumpy;
        while(head!=nullptr)
        {
            int num=head->val;
            if(head->next!=nullptr && head->next->val==num)
            {
                while(head!=nullptr && head->val==num)
                {
                    head=head->next;
                }
                continue;
            }
            else
            {
                cur->next=head;
                cur=cur->next;
                head=head->next;
            }
            
        }
        cur->next=nullptr;
        return dumpy->next;
    }
};
