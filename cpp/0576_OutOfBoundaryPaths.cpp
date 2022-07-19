class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        const int mod = 1e9+7;
        if(maxMove<1)
            return 0;
        vector<vector<vector<int>>> dp(m+2,vector<vector<int>>(n+2,vector<int>(maxMove,0)));
        if(m==1 && n==1)
            dp[1][1][0]=4;
        else if(m==1 || n==1)
        {
            if(m==1)
            {
                dp[1][1][0]=3;
                dp[1][n][0]=3;
                for(int i=2;i<n;i++)
                    dp[1][i][0]=2;
            }
            if(n==1)
            {
                dp[1][1][0]=3;
                dp[m][1][0]=3;
                for(int i=2;i<m;i++)
                    dp[i][1][0]=2;
            }
        }
        else
        {
            dp[1][1][0]=2;
            dp[1][n][0]=2;
            dp[m][1][0]=2;
            dp[m][n][0]=2;
            for(int i=2;i<m;i++)
            {
                dp[i][1][0]=1;
                dp[i][n][0]=1;
            }
            for(int i=2;i<n;i++)
            {
                dp[1][i][0]=1;
                dp[m][i][0]=1;
            }

        }
        for(int k=1;k<maxMove;k++)
        {
            for(int i=1;i<m+1;i++)
            {
                for(int j=1;j<n+1;j++)
                {
                    
                        dp[i][j][k]=(dp[i-1][j][k-1]+dp[i+1][j][k-1])%mod+(dp[i][j-1][k-1]+dp[i][j+1][k-1])% mod;
                        dp[i][j][k]=dp[i][j][k]%mod;
                    
                }
            }
        }
        // for(int k=0;k<maxMove;k++)
        // {
        //     for(int i=0;i<m+2;i++)
        //     {
        //         for(int j=0;j<n+2;j++)
        //         {
        //             cout<<dp[i][j][k]<<" ";
        //         }
        //         cout<<endl;
        //     }
        //     cout<<endl;
        //     cout<<endl;
        // }
        int res=0;
        for(int i=0;i<maxMove;i++){
            res+=dp[startRow+1][startColumn+1][i];
            res=res% mod;
        }
        return res% mod;
        
    }
};
