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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || head==|| head->next==nullptr)
            return head;
        int n=0;
        ListNode * cur=head;
        while(cur!=nullptr)
        {
            n++;
            if(cur->next)
                cur=cur->next;
            else
            {
                cur->next=head;
                cur=nullptr;
            } 
        }

        k=k%n;
        int vk=n-k;
        cur=head;
        for(int i=1;i<vk;i++)
        {
            cur=cur->next;
        }
        head=cur->next;
        cur->next=nullptr;
        return head;
        
    }
};
