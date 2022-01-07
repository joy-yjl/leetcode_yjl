#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        from heapq import heappush, heappop, heapreplace, heapify
        head=ListNode(-1)
        cur=head

        heap=[(n.val,n) for n in lists if n]
        heapify(heap)
        while heap:
            val,node =heap[0]
            cur.next=node
            cur=node
            if node.next:
                heapreplace(heap,(node.next.val,node.next))
            else:
                heappop(heap)

        return head.next
