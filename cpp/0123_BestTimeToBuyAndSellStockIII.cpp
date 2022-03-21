

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(3,vector<int>(2,0)));
        for(int i=0;i<n+1;i++)
        {
            dp[i][0][0]=0;
            dp[i][0][1]=INT_MIN;
        }
        for(int i=0;i<3;i++)
        {
            dp[0][i][0]=0;
            dp[0][i][1]=INT_MIN;
        }

        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<3;j++)
            {
                
                dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j][1]+prices[i-1]);
                dp[i][j][1]=max(dp[i-1][j][1],dp[i-1][j-1][0]-prices[i-1]);
            }
        }

        return dp[n][2][0];
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int firstBuy = INT_MAX, secondBuy = INT_MAX, firstProfit = 0, secondProfit = 0;
        for(int currPrice: prices) {
            firstBuy = min(firstBuy, currPrice);
            firstProfit = max(firstProfit, currPrice - firstBuy);
            secondBuy = min(secondBuy, currPrice - firstProfit);
            secondProfit = max(secondProfit, currPrice - secondBuy);
        }
        return secondProfit;
    }
};



