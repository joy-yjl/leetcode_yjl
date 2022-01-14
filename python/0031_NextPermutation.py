class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        i=j=len(nums)-1
        while i>0 and nums[i-1]>=nums[i]:
            i-=1
        if i==0:
            nums[:]=nums[::-1]
        else:
            while nums[j] <= nums[i-1]:
                j -= 1
            nums[i-1], nums[j] = nums[j], nums[i-1]
            nums[i:]= nums[len(nums)-1:i-1:-1]

