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


// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//         if(l1 == NULL){
//             return l2;
//         }
//         if(l2 == NULL){
//             return l1;
//         }        
//         if(l1->val < l2->val){
//             l1->next = mergeTwoLists(l1->next, l2);
//             return l1;
//         }
//         else{
//             l2->next = mergeTwoLists(l1, l2->next);
//             return l2;            
//         }
//     }
// };
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head=nullptr;
        ListNode* cur=nullptr;
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;
        if(list1->val < list2->val){
            head = list1;
            cur = list1;
            list1 = list1->next;
        }
        else{
            head = list2;
            cur = list2;
            list2 = list2->next;
        }
        while(list1&&list2)
        {
            
            if(list1->val<list2->val)
            {
                cur->next=list1;
                cur=cur->next;
                list1=list1->next;
            }
            else
            {
                cur->next=list2;
                cur=cur->next;
                list2=list2->next;
            }
        }
        if(list1)
            cur->next=list1;
        if(list2)
            cur->next=list2;
        return head;  
    }
};
