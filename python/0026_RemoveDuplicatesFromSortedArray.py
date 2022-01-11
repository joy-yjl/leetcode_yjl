class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res=1
        for i in range(1,len(nums)):
            if(nums[i]==nums[i-1]):
                i+=1
            else:
                nums[res]=nums[i]
                res+=1

        return res

