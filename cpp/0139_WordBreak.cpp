class Solution {
public:
    bool helper(string & s,vector<string>& wordDict,int start)
    {
        if(start==s.size())
            return true;
        bool res=false;
        for(int i=0;i<wordDict.size();i++)
        {
            if(s[start]==wordDict[i][0])
            {
                int n=wordDict[i].size();
                int j=0;
                while(j<n && (j+start)<s.size())
                {
                    if(s[j+start]!=wordDict[i][j])
                        break;
                    j++;
                }
                if(j==n)
                {
                    res=helper(s,wordDict,j+start);
                    if(res==true)
                        return true;
                }

            }
        }
        return res;

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.size()==0 || wordDict.size()==0)
            return true;
        return helper(s,wordDict,0);
        
        
    }
};


class Solution {
public:
    bool helper(string & s,vector<string>& wordDict,int start,vector<int> &dp)
    {
        if(start==s.size())
            return true;
        if (dp[start] != -1) {
            return dp[start] == 1 ? true : false;
        }
        bool res=false;
        for(int i=0;i<wordDict.size();i++)
        {
            if(s[start]==wordDict[i][0])
            {
                int n=wordDict[i].size();
                int j=0;
                while(j<n && (j+start)<s.size())
                {
                    if(s[j+start]!=wordDict[i][j])
                        break;
                    j++;
                }
                if(j==n)
                {
                    if(helper(s,wordDict,j+start,dp))
                    {
                        dp[start]=1;
                        return true;
                    }
                }

            }
            
        }
        dp[start]=0;
        return res;

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.size()==0 || wordDict.size()==0)
            return true;
        vector<int> dp(s.size(),-1);
        return helper(s,wordDict,0,dp);
        
        
    }
};
