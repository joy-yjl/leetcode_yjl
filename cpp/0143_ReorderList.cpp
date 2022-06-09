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
    void reorderList(ListNode* head) {
        stack<ListNode *> s;
        ListNode* cur=head;
        int n=0;
        while(cur!=nullptr)
        {
            s.push(cur);
            cur=cur->next;
            n++;
        }
        n=(n-1)/2;
        cur=head;
        ListNode * curh=head;

        for(int i=0;i<n;i++)
        {
            cur=cur->next;
            curh->next=s.top();
            s.pop();
            curh=curh->next;
            curh->next=cur;
            curh=curh->next;
        }
        if(curh!=s.top()){
            curh->next=s.top();
            s.pop();
            curh=curh->next;
        }
        curh->next=nullptr;

        return;
        
    }
};
