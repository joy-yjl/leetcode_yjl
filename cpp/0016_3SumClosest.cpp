class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int offset=INT_MAX;
        int res=0;
        for(int i=0;i<nums.size()-2;i++)
        {
            int left=i+1;
            int right=nums.size()-1;
            while(left<right)
            {
                int sum=nums[i]+nums[left]+nums[right];
                int tmp= sum>target?sum-target:target-sum;
                if(tmp<offset)
                {
                    offset=tmp;
                    res=sum;
                }
                if(sum>target)
                {
                    right--;
                }
                else if(sum<target)
                {
                    left++;
                
                }
                else
                    return res;            }
        }
    return res;
        
    }
};
