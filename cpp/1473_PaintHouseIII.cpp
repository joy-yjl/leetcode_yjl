class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>>  dp(m,vector<vector<int>>(n,vector<int>(target,INT_MAX)));
        if(houses[0]==0)
        {
            for(int i=0;i<n;i++)
            {
                dp[0][i][0]=cost[0][i];
            }
        }
        else
        {
            dp[0][houses[0]-1][0]=0;
        }

        for(int i=1;i<m;i++)
        {
            if(houses[i]!=0)
            {
                dp[i][houses[i]-1][0]=dp[i-1][houses[i]-1][0];
                for(int j=0;j<n;j++)
                {
                    for(int k=1;k<target;k++)
                    {
                        if(houses[i]-1 == j ) // &&  dp[i-1][j][k]!= MIN_MAX
                            dp[i][houses[i]-1][k]=min(dp[i][houses[i]-1][k],dp[i-1][j][k]);
                        else//(houses[i]-1 !=j ) //  && dp[i-1][j][k-1]!= MIN_MAX
                            dp[i][houses[i]-1][k]=min(dp[i][houses[i]-1][k],dp[i-1][j][k-1]);
                    }
                }
            }
            else
            {

                for(int j=0;j<n;j++)
                {
                    if(dp[i-1][j][0]!= INT_MAX)
                        dp[i][j][0]=dp[i-1][j][0]+cost[i][j];
                    for(int j2=0;j2<n;j2++)
                    {
                        for(int k=1;k<target;k++)
                        {
                            if(j==j2 && dp[i-1][j2][k]!= INT_MAX)
                                dp[i][j][k]=min(dp[i][j][k],dp[i-1][j2][k]+cost[i][j]);
                            if(j!=j2 && dp[i-1][j2][k-1]!= INT_MAX)
                                dp[i][j][k]=min(dp[i][j][k],dp[i-1][j2][k-1]+cost[i][j]);
                        }
                    }
                }   
            }
            
        }
        int res=INT_MAX;
        for(int j=0;j<n;j++)
            res=min(res,dp[m-1][j][target-1]);
        return res==INT_MAX?-1:res;
    }
};



