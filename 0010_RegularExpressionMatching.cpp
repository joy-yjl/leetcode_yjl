/*
动态规划
先考虑边界

然后考虑p是不是走到了*，不是*怎么处理，是*又分为不重复，重复一次和重复多次三个情况
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        vector<vector<bool>> dp(m+1,vector<bool> (n+1,false));
        dp[0][0]=true;
        for(int j=1;j<n+1;j++)
        {
            if(j>1 && dp[0][j-2] && p[j-1]=='*')
                dp[0][j]=true;        
        }
        for (int i=1;i<m+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(p[j-1]!='*')
                {
                    if( dp[i-1][j-1] && (s[i-1]==p[j-1]|| p[j-1]=='.'))
                        dp[i][j]=true;
                }
                else
                {
                    if( j>1&& dp[i][j-2] || dp[i][j-1] || (j>1 &&  dp[i-1][j] && (s[i-1]==p[j-2]||p[j-2]=='.') ) )
                        dp[i][j]=true;
                }
            }
        }

        return dp[m][n];
            
        
    }
};
