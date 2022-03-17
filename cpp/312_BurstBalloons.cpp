class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        for (int i = n; i >= 0; i--) 
        {
            for (int j = i + 1; j < n + 2; j++) 
            {
                for (int k = i + 1; k < j; k++) 
                {
                    if(i==0)
                    {
                        dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + 1*nums[j-1]*nums[k-1]);
                    }
                    else
                        dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + nums[i-1]*nums[j-1]*nums[k-1]);
                }
            }
        }
        return dp[0][n+1];
        
    }
};
