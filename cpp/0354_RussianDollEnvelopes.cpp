
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end());
        vector<int> dp(envelopes.size(),1);
        for(int i=1;i<envelopes.size();i++)
        {
            int max_=0;
            for(int j=0;j<i;j++)
            {
                if(envelopes[j][0]<envelopes[i][0] && envelopes[j][1]<envelopes[i][1])
                {
                    max_=max(max_,dp[j]);
                }
            }
            dp[i]=max_+1;
        }
        int res=1;
        for(int i=0;i<dp.size();i++)
        {
            res=max(res,dp[i]);
        }
        return res;

        
    }
};


class Solution {
public:
    static bool comp1(const vector<int> &a ,const vector<int> &b)
    {
            if(a[0]==b[0])
            {
                    return a[1]>b[1];
            }
            return a[0]<b[0];
    }
    static bool comp2(const vector<int> &a ,const vector<int> &b)
    {
            return a[1]<b[1];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end());
       
        vector<vector<int>> dp;
        for(int i=0;i<envelopes.size();i++)
        {
            auto it=std::lower_bound(dp.begin(),dp.end(),envelopes[i],comp2);
            if(it==dp.end())
            {
                dp.push_back(envelopes[i]);
            }
            else
            {
                *it=envelopes[i];
            }

        }
        return dp.size();
    }
};


