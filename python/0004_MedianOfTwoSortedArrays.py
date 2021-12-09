class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        l=len(nums1)+len(nums2)

        if l%2 == 0:
        	return (self.findK(nums1, nums2, l //2) + self.findK(nums1, nums2, l // 2 - 1)) / 2.0
        else:
        	return self.findK(nums1, nums2, l // 2)
        
    def findK(self,nums1,nums2,k):
        if not nums1:
        	return nums2[k]
        if not nums2:
        	return nums1[k]
        i1, i2 = len(nums1) // 2 , len(nums2) // 2
        m1, m2 = nums1[i1], nums2[i2]

        if i1 + i2 < k:
        	if m1 > m2:
        		return self.findK(nums1, nums2[i2 + 1:], k - i2 - 1)
        	else:
        		return self.findK(nums1[i1 + 1:], nums2, k - i1 - 1)
        else:
        	if m1 > m2:
        		return self.findK(nums1[:i1], nums2, k)
        	else:
        		return self.findK(nums1, nums2[:i2], k)
