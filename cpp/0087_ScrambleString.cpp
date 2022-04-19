class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;
        int n = s1.size();

        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(n+1,false)));

        for(int len=1;len<=n;len++)
        {
            for(int i=0;i<=n-len;i++)
            {
                for(int j=0;j<=n-len;j++)
                {
                    if(len==1)
                    {
                        dp[i][j][1]=(s1[i]==s2[j]);
                    }
                    else
                    {
                        for(int k=1;k<len;k++)
                        {
                            if( (dp[i][j][k] && dp[i+k][j+k][len-k]) || (dp[i+k][j][len-k] && dp[i][j+len-k][k]) )
                            {
                                dp[i][j][len]=true;
                                break;
                            }

                        }
                    }

                } 
            }
        }
        return dp[0][0][n];
        
    }
};
