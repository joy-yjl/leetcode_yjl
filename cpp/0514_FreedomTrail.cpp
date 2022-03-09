class Solution {
public:
    int helper(string ring, string key,int indexr,int indexk,vector<vector<int>>& dp)
    {
        if(indexk==key.size())
            return 0;
        if(dp[indexr][indexk]!=0)
            return dp[indexr][indexk];
        int res=INT_MAX;
        for(int i=0;i<ring.size();i++)
        {
            if(ring[(indexr+i)%ring.size()]==key[indexk])
            {
                int tmp=i>ring.size()-i ? ring.size()-i:i;
                tmp=tmp+helper(ring,key,(indexr+i)%ring.size(),indexk+1,dp);
                res=min(res,tmp);

            }
        }
        dp[indexr][indexk]=res+1;

        return res+1;
    }
    int findRotateSteps(string ring, string key) {
        int n=ring.size();
        int m=key.size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        return helper(ring,key,0,0,dp);
        
    }
};
