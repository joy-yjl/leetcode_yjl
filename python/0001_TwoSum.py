class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        my_dict={}
        res=[]
        for i in range(len(nums)) :
            if not my_dict.has_key(nums[i]):
                my_dict[target-nums[i]]=i
            else:
                res.append(i)
                res.append(my_dict[nums[i]])
                break
                
        return res
