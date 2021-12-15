class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res=[]
        nums.sort()#从小到大

        for i in range(len(nums)-2):
            if nums[i] > 0:
                break
            if i>0 and nums[i] ==nums[i-1]:
                continue

            target=nums[i]
            left,right=i+1,len(nums)-1
            while right>left:
                if target+nums[left]+nums[right]==0:
                    res.append([target,nums[left],nums[right]])
                    while left < right and nums[left] == nums[left+1]:
                        left += 1
                    while left < right and nums[right] == nums[right-1]:
                        right -= 1
                    left += 1; right -= 1
                elif target+nums[left]+nums[right]<0:
                    left+=1
                else:
                    right-=1

        return res


