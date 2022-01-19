class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        left=self.findFist(nums,target)
        right=self.findLast(nums,target)
        return [left,right] if left<=right else [-1,-1]
        
    def findFist(self, nums, target):
        left,right=0,len(nums)-1
        while left<=right:
            mid=left+(right-left)/2
            if nums[mid]<target:
                left=mid+1
            else:
                right=mid-1
        return left


    def findLast(self, nums, target):
        left,right=0,len(nums)-1
        while left<=right:
            mid=left+(right-left)/2
            if nums[mid]<=target:
                left=mid+1
            else:
                right=mid-1
        return right
