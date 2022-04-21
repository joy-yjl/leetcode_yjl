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
    ListNode* successor = nullptr; 
    ListNode* reverseList(ListNode* head,int k) {
        if(k==1)
        {
        successor = head->next;
        return head;
        }
        
       ListNode * last=reverseList(head->next,--k);
       head->next->next=head;
       head->next=successor;
       return last;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==1)
            return reverseList(head,right);

        ListNode * rever=reverseBetween(head->next,left-1,right-1);
        head->next=rever;
        return head;
        
    }
};
