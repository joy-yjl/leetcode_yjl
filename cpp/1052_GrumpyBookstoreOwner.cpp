class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum=0,uns=0;
        for(int i=0;i<customers.size();i++)
        {
            sum+=customers[i];
            if(grumpy[i]==1)
                uns+=customers[i];
        }
        int win=0;
        for(int i=0;i<minutes;i++)
        {
            if(grumpy[i]==1)
                win+=customers[i];
        }
        int tmp=win;
        for(int i=minutes;i<customers.size();i++)
        {
            tmp+=grumpy[i]?customers[i]:0;
            tmp-=(grumpy[i-minutes]?customers[i-minutes]:0);
            win=max(win,tmp);
            // cout<<win<<endl;
        }
        return sum-(uns-win);
        
    }
};
