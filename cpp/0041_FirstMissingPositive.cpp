class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i=0;
        while(i<nums.size())
        {
            if(nums[i]>0 && nums[i]<=nums.size() && nums[i]!=(i+1) && nums[nums[i]-1]!=nums[i])
            {
                int tmp=nums[nums[i]-1];
                nums[nums[i]-1]=nums[i];
                nums[i]=tmp;
            }
            else
                i++;
        }
        for(i=0;i<nums.size();i++)
        {
            if(nums[i]!=(i+1))
                return i+1;
        }
        return nums.size()+1;
        
    }
};
