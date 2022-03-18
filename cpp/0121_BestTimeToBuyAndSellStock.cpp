class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0;
        for(int i =0;i<prices.size()-1;i++)
        {
            for(int j=i+1;j<prices.size();j++)
            {
                if((prices[j]-prices[i])>res)
                    res=prices[j]-prices[i];

            }
        } 
        return res;
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0;
        int buy=INT_MAX;
        // int sell=0;
        for(int i =0;i<prices.size();i++)
        {
            if(prices[i]<buy)
                buy=prices[i];
            int tmp=prices[i]-buy;
            if(tmp>res)
                res=tmp;
        } 
        return res;
    }
};
