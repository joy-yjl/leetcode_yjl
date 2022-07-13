class Solution {
public:
    bool helper(vector<int>& matchsticks,vector<int>& vis,int target, int cur_sum, int index,int k)
    {
        if(k==1)
            return true;
        if(target==cur_sum)
            return helper(matchsticks,vis,target,0,0,k-1);

        for(int i=index;i<matchsticks.size();i++)
        {
            if(vis[i] || cur_sum + matchsticks[i] > target)
                continue;
         
            vis[i]=1;
            if(helper(matchsticks,vis,target,cur_sum+matchsticks[i],i+1,k))
                return true;
            vis[i]=0;
            
        }
        return false;
        
    }
    bool makesquare(vector<int>& matchsticks) {
        int ave=0;
        for(int i=0;i<matchsticks.size();i++)
            ave+=matchsticks[i];
        if (matchsticks.size() < 4 || ave%4) 
            return false;
        vector<int> vis(matchsticks.size(),0);
        return helper(matchsticks,vis,ave/4,0,0,4);
        
    }
};



