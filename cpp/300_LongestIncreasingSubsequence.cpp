class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        for(int i=1;i<nums.size();i++)
        {
            int max_=0;
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    max_=max(max_,dp[j]);
                }
            }
            dp[i]=max_+1;
        }
        int res=1;
        for(int i=0;i<dp.size();i++)
        {
            res=max(res,dp[i]);
        }
        return res;
        
    }
};
