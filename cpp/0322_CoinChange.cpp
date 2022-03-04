class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,0);
        for(int i=1;i<=amount;i++)
        {
            int min_=INT_MAX;
            for(int j=0;j<coins.size();j++)
            {
                if(i-coins[j]<0)
                    continue;
                min_=min(min_,dp[i-coins[j]]);

            }
            if(min_==INT_MAX)
                dp[i]=INT_MAX;
            else
                dp[i]=min_+1;

        }
        return dp[amount]==INT_MAX?-1:dp[amount];
        
    }
};
