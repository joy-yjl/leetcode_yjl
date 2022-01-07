/*
单纯的把几个链表和在一起，需要一个新的list来存结果非常不好的解决方法
*/
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        ListNode * head=new ListNode(0);
        ListNode * cur=head;

        for(int i=0;i<k;i++)
        {
            if (lists[i]==nullptr)
            {
                lists.erase( lists.begin() + i ); 
                k--;
                i--;
            }
        }
        while(k>0)
        {
            int tmp=INT_MAX;
            int minindex=0;
            for(int i=0;i<k;i++)
            {
                if(lists[i]->val<tmp)
                {
                    tmp=lists[i]->val;
                    minindex=i;
                }
                
            }
            cur->next=new ListNode(lists[minindex]->val);
            cur=cur->next;
            lists[minindex]=lists[minindex]->next;
            if(lists[minindex]==nullptr)
            {
                lists.erase( lists.begin() + minindex );
                k--; 
            }
        }

        return head->next;
        
    }
};


/*
分治法
*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        int n = lists.size();
        while (n > 1) {
            int k = (n + 1) / 2;
            for (int i = 0; i < n / 2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[i + k]);
            }
            n = k;
        }
        return lists[0];
        
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;
        ListNode* head=new ListNode(-1);
        ListNode* cur=head;
        while(list1&&list2)
        {
            
            if(list1->val<list2->val)
            {
                cur->next=list1;
                list1=list1->next;
            }
            else
            {
                cur->next=list2;
                list2=list2->next;
            }
            cur=cur->next;
        }
        if(list1) cur->next=list1;
        if(list2) cur->next=list2;
        return head->next;  
    }
};

/*
最小堆,最快
*/
class myHeap {
    public:
    vector<ListNode*> heap;
    void buildHeap(vector<ListNode*>& lists);
    void adjustHeap(int start);
    ListNode *getTop();
    void pop();
    int getParent(int i) {return (i-1)/2;}
    int getLeft(int i) {return i*2+1;}
    int getRight(int i) {return i*2+2;}
    myHeap(vector<ListNode*>& lists);
};
myHeap::myHeap(vector<ListNode*>& lists) {
    buildHeap(lists);
}
void myHeap::buildHeap(vector<ListNode*>& lists) {
    for(auto l:lists) {
        if(!l) continue;
        heap.push_back(l);
    }
    for(int i=getParent(heap.size()-1);i>=0;--i) {
        int l = getLeft(i), r = getRight(i);
        if (l >= heap.size()) break;
        if (r < heap.size()) {
            int min_v = min(heap[l]->val,heap[r]->val);
            if (heap[i]->val < min_v)  continue;
            if (heap[l]->val < heap[r]->val) {
                swap(heap[l], heap[i]);
                adjustHeap(l);
            } else {
                swap(heap[r], heap[i]);
                adjustHeap(r);
            }
        } else {
            if (heap[l]->val > heap[i]->val) continue;
            swap(heap[l], heap[i]);
                adjustHeap(l);
        }
    }
    
}
void myHeap::adjustHeap(int start=0) {
    for(int i=start;i<=getParent(heap.size()-1);) {
        int l = getLeft(i), r = getRight(i);
        if (l >= heap.size()) break;
        if (r<heap.size()) {
            if (heap[i]->val < heap[l]->val && heap[i]->val < heap[r]->val) break;
            if(heap[l]->val > heap[r]->val) {
                swap(heap[i], heap[r]);
                i=r;
            } else {
                swap(heap[i], heap[l]);
                i=l;
            }
        } else {
            if (heap[i]->val > heap[l]->val) {
                swap(heap[i], heap[l]);
                i=l;
            } else {break;}
        }
    }
    
}


ListNode *myHeap::getTop() {
    if (heap.size() >0) return heap[0];
    return NULL;
}
void myHeap::pop() {
    if (heap.size()<=0) return;
    heap[0] = heap[0]->next;
    if (!heap[0]) {
        heap[0] = heap[heap.size()-1];
        heap.pop_back();
    }
    adjustHeap();
}
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = new ListNode(-1);
        ListNode *cur=head;
        myHeap mh(lists);
        while(mh.getTop())
        {
            cur->next = new ListNode(mh.getTop()->val);
            cur = cur->next;
            mh.pop();
        }
        return head->next;
    }
};

/*
slt的最小堆
*/

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // auto cmp = [](ListNode*& a, ListNode*& b) {
        //     return a->val > b->val;
        // };
        struct cmp
        {
            bool operator()(ListNode* &a,ListNode* &b)
            {
                return a->val>b->val;
            }
        };
        

        //priority_queue<ListNode*, vector<ListNode*>, decltype(cmp) >  heap(cmp);
        priority_queue<ListNode*, vector<ListNode*>, cmp >  heap;
        for (ListNode* node : lists) {
            if (node) heap.push(node);
        }
        ListNode *head = new ListNode(-1), *cur = head;
        while (!heap.empty()) {
            ListNode* t = heap.top(); heap.pop();
            cur->next = t;
            cur = cur->next;
            if (cur->next) heap.push(cur->next);
        }
        return head->next;
        
    }

    
};
