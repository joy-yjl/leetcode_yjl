
class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        res,offset=(nums[0]+nums[1]+nums[2]),abs(target-(nums[0]+nums[1]+nums[2]))
        nums.sort()#从小到大

        for i in range(len(nums)-2):
            # if i>0 and nums[i] ==nums[i-1]:
            #     continue

            left,right=i+1,len(nums)-1
            while right>left:
                isum=nums[i]+nums[left]+nums[right]
                tmp=abs(target-isum)
                if tmp<offset:
                    offset=tmp
                    res=isum

                if isum>target:
                    right -= 1
                elif isum<target:
                    left+=1
                else:
                    return res

        return res
        


