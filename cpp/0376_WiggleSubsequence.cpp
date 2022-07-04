class Solution {
public:

    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<2)
            return 1;
        if(nums.size()==2&& nums[1]!=nums[0])
            return 2;
        vector<int> dp(nums.size(),0);
        int start=0;
        while(start+1<nums.size() && nums[start]==nums[start+1])
        {
            dp[start]=1;
            start++;
            
        }
        dp[start]=1;
        if(start+1>=nums.size())
            return 1;
        dp[start+1]=2;
        bool flag=0;  //0:该找小的了  1:该找大的了  
        int before=start+1;
        if(nums[start]>nums[start+1])
            flag=1;
        for(int i=start+2;i<nums.size();i++)
        {
            if(flag==0)
            {
                if(nums[i]<nums[i-1])
                {
                    dp[i]=dp[before]+1;
                    before=i;
                    flag=1;
                }
                else
                    dp[i]=dp[before];

            }
            else
            {
                if(nums[i]>nums[i-1])
                {
                    dp[i]=dp[before]+1;
                    before=i;
                    flag=0;
                }
                else
                    dp[i]=dp[before];
            }
        }
        

        return dp[nums.size()-1];
        
    }
};
