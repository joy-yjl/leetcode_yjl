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
/*
内存开辟过多
*/
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head,int k) {
        if(head==nullptr || head->next==nullptr)
            return head;
       ListNode * res=new ListNode(-1);
       ListNode * cur=res;

       while (head)
       {
           ListNode * tmp=new ListNode(-1);
           ListNode * head_2=head;
           int i=0;
           for(;i<k;i++)
           {
               if(!head)
                   break;
               ListNode * t=new ListNode(head->val);
               t->next=tmp;
               tmp=t;
               head=head->next;
           }
           if(i!=k)
           {
               cur->next=head_2;
               return res->next;
           }
           cur->next=tmp;
           for(int j=0;j<k;j++)
           {
               cur=cur->next;
           }
           cur->next=nullptr;


       }
        return res->next;
    }
};

/*
通过反转链表实现，不开辟新的空间
*/

class Solution {
public:
    ListNode * reverse(ListNode * head)
    {
        if(head==nullptr || head->next==nullptr)
            return head;
        ListNode * last=head->next;
        ListNode * before=nullptr;

        while(last)
        {
            head->next=before;
            before=head;
            head=last;
            last=last->next;
        }
        head->next=before;

        return head;
    }

    ListNode* reverseKGroup(ListNode* head,int k) {
        if(head==nullptr || head->next==nullptr)
            return head;
        ListNode * res=new ListNode(-1,head);
        ListNode * before=res;
        ListNode * last=head;
        ListNode * cur=head;
        ListNode * tail=head;


        while(cur)
        {
            tail=head;

            for(int i=0;i<k-1;i++)
            {
                if(!cur)
                    break;
                cur=cur->next;

            }

            if(!cur)
            {
                before->next=head;
                break;
            }
            last=cur->next;
            cur->next= nullptr;


            before->next=reverse(head);
            before=tail;
            cur=last;
            head=last;


        }
        return res->next;



    }
};
