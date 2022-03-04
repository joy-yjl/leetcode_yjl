class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=0;
        if(rows!=0)
            cols=matrix[0].size();

        vector<vector<int>>  dp(rows+1,vector<int>(cols+2,INT_MAX));
        for(int i=0;i<cols+2;i++)
            dp[0][i]=0;
        for(int i=1;i<rows+1;i++)
        {
            for(int j=1;j<cols+1;j++)
            {
                dp[i][j]=min(min(dp[i-1][j-1],dp[i-1][j]),dp[i-1][j+1]);
                dp[i][j]=dp[i][j]+matrix[i-1][j-1];
            }
        }
        int res=INT_MAX;
        for(int i=1;i<cols+1;i++)
        {
            res=min(res,dp[rows][i]);

        }
        return res;
    }
};
