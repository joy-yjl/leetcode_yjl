class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        res=0
        for i in range(len(nums)):
            if(nums[i]==val):
                i+=1
            else:
                nums[res]=nums[i]
                res+=1

        return res


class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        while val in nums:
            nums.remove(val)
        return len(nums)


