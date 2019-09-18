class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if (n<2)
            return s;
        vector<vector<int>> dp(n,vector<int>(n,0));
        int left=0;
        int right=0;
        for (int i=0;i<n;i++)
            dp[i][i]=1;
        for (int edge=1;edge<n;edge++)
        {
            for(int i=0,j=i+edge;j<n;i++,j++)
            {
                if(s[i]==s[j])
                {
                    if(edge==1 || dp[i+1][j-1]==1)
                    {
                        dp[i][j]=1;
                        left=i;
                        right=j;
                        
                    }
                }
            }
        }
        return s.substr(left,right-left+1);
        
    }
};
