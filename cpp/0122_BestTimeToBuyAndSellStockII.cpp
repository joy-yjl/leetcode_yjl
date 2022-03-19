class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> dp1;
        vector<int> dp2;
        dp1.push_back(prices[0]);
        dp2.push_back(prices[n-1]);
        int res=0;
        for(int i=1;i<n;i++)
        {
            if(prices[i]<prices[i-1])
                dp1.push_back(prices[i]);
            if(prices[n-i-1]>prices[n-i])
                dp2.push_back(prices[n-i-1]);
        }
        int m=dp1.size();
        for(int i=0;i<m;i++)
        {
            if(dp1[i]>=dp2[m-1-i])
                continue;
            res+=dp2[m-1-i]-dp1[i];       
        }
        return res;
        
    }
};
