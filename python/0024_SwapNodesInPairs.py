# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head==None or head.next==None:
            return head

        res=head.next
        cur=ListNode(-1)
        tmp=None

        while head:
            if head.next:
                cur.next=head.next
                cur=cur.next
                tmp=head.next.next
            else:
                tmp=None

            cur.next=head
            cur=cur.next
            head=tmp

        cur.next=None
        return res


