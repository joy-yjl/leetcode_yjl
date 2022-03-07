class Solution {
public:
    bool help(vector<int>& nums,int index,int target)
    {
        if(index>=nums.size()||target<0)
            return false;
        if(target==0)
            return true;
        return (help(nums,index+1,target) || help(nums,index+1,target-nums[index]));
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        if(sum%2)
            return false;
        sum=sum/2;
        return help(nums,0,sum);
        
    }
};

class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        if(sum%2)
            return false;
        sum=sum/2;

        vector<bool> dp(sum+1,0);
        dp[0]=true;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=sum;j>0;j--)
            {
                if (j - nums[i] >= 0) 
                {
                    dp[j] = (dp[j] || dp[j - nums[i]]);
                }
            }
        }
        return dp[sum];
        
    }
};
