#python 判断key在不在字典里 可以用dict.has_key 也可以用 key in dict 
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
