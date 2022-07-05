class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        if(n<2)
            return n;
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
            dp[i][i]=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if((dp[j+1][i-1]==1 || j+1>=i-1) && s[i]==s[j])
                    dp[j][i]=1;
                else
                    dp[j][i]=0;
            }
        }
        int res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(dp[i][j]==1)
                    res++;
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        return res;
    }
};
