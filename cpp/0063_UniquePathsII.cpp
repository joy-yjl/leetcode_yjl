class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        if(obstacleGrid[0][0]==0)
            dp[1][1]=1;
        for(int i=1;i<m+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(i==1 && j==1)
                    continue;
                if(obstacleGrid[i-1][j-1]==0)
                    dp[i][j]=dp[i][j-1]+dp[i-1][j];
                else
                    dp[i][j]=0;
                
            }
        }
        // for(int i=0;i<m+1;i++)
        // {
        //     for(int j=0;j<n+1;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[m][n];
        
    }
};
