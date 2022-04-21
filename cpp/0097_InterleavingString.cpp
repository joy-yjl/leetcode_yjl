class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        if(n+m != s3.size())
            return false;

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        dp[0][0]=1;
        for(int i=0;i<n;i++)
        {
            if(s1[i]==s3[i] && dp[i][0]==1)
                dp[i+1][0]=1;
        }
        for(int i=0;i<m;i++)
        {
            if(s2[i]==s3[i] &&  dp[0][i]==1)
                dp[0][i+1]=1;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if( (s3[i+j-1]==s1[i-1] && dp[i-1][j]==1) ||  (s3[i+j-1]==s2[j-1] && dp[i][j-1]==1))
                    dp[i][j]=1;
            }
        }
        // for(int i=0;i<n+1;i++)
        // {
        //     for(int j=0;j<m+1;j++)
        //     {
        //         cout<<dp[i][j]<<' ';
        //     }
        //     cout<<endl;
        // }

        return dp[n][m];
    }
};

