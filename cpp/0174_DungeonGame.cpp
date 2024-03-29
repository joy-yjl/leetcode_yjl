class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rows=dungeon.size();
        if(rows==0)
            return 1;
        int cols=dungeon[0].size();
        vector<vector<int>> dp(rows,vector<int>(cols,0));

        dp[rows-1][cols-1]=max(0-dungeon[rows-1][cols-1],0);
        for(int i=rows-2;i>=0;i--)
            dp[i][cols-1]=max(dp[i+1][cols-1]-dungeon[i][cols-1],0);
        for(int i=cols-2;i>=0;i--)
            dp[rows-1][i]=max(dp[rows-1][i+1]-dungeon[rows-1][i],0);
        for(int i=rows-2;i>=0;i--)
        {
            for(int j=cols-2;j>=0;j--)
            {
                dp[i][j]=max(min(dp[i][j+1],dp[i+1][j])-dungeon[i][j],0);
            }
        }

        return dp[0][0]+1;
        
    }
};
