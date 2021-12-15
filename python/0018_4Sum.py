# class Solution(object):
#     def fourSum(self, nums, target):
#         """
#         :type nums: List[int]
#         :type target: int
#         :rtype: List[List[int]]
#         """
#         res=[]
#         nums.sort()#从小到大

#         for i in range(len(nums)-3):
#             if i>0 and nums[i] ==nums[i-1]:
#                     continue
#             for j in range(i+1,len(nums)-2):
#                 if j>i+1 and nums[j] ==nums[j-1]:
#                     continue
                
#                 left,right=j+1,len(nums)-1
#                 sum_t=nums[i]+nums[j]
#                 while right>left:
#                     if sum_t+nums[left]+nums[right]==target:
#                         res.append([nums[i],nums[j],nums[left],nums[right]])
#                         while left < right and nums[left] == nums[left+1]:
#                             left += 1
#                         while left < right and nums[right] == nums[right-1]:
#                             right -= 1
#                         left += 1; right -= 1
#                     elif target-sum_t-nums[left]-nums[right]>0:
#                         left+=1
#                     else:
#                         right-=1

#         return res


class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """

        def findNsum(l, r, target, N, result, results):
            if r-l+1 < N or N < 2 or target < nums[l]*N or target > nums[r]*N:  # early termination
                return
            if N == 2: # two pointers solve sorted 2-sum problem
                while l < r:
                    s = nums[l] + nums[r]
                    if s == target:
                        results.append(result + [nums[l], nums[r]])
                        l += 1
                        while l < r and nums[l] == nums[l-1]:
                            l += 1
                    elif s < target:
                        l += 1
                    else:
                        r -= 1
            else: # recursively reduce N
                for i in range(l, r+1):
                    if i == l or (i > l and nums[i-1] != nums[i]):
                        findNsum(i+1, r, target-nums[i], N-1, result+[nums[i]], results)

        nums.sort()
        results = []
        findNsum(0, len(nums)-1, target, 4, [], results)
        return results
