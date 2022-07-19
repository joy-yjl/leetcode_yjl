class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> dp(n,0);
        unordered_map<int,int> dict;
        dp[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            dp[i]=dp[i-1]+nums[i];
        }
        int res=0;
        for(int i=0;i<n;i++)
        {
            if(dp[i]==k)
                res++;
            if(dict.count(dp[i]-k))
                res+=dict[dp[i]-k];
            dict[dp[i]]++;
        }
        return res;
        
    }
};
