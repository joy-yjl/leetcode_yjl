


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=getFirst(nums,target);
        int right=getLast(nums,target);
        return right>=left? vector<int>{left, right} : vector<int>{-1, -1};
        
    }
    int getFirst(vector<int>& nums, int target)
    {
        int left=0,right=nums.size()-1;
        
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]<target)
                left=mid+1;
            else
                right=mid-1;
        }
        return left;
    }
    int getLast(vector<int>& nums, int target)
    {
        int left=0,right=nums.size()-1;
        
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]<=target)
                left=mid+1;
            else
                right=mid-1;
        }
        return right;
    }
};
