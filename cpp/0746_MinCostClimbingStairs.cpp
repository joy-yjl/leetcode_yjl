
 int minCostClimbingStairs(vector<int>& cost) {
        for(int i=2;i<cost.size();i++)
        {
            cost[i]+=min(cost[i-1],cost[i-2]);
        }
        return min(cost[cost.size()-1],cost[cost.size()-2]);
    }
class Solution {
public:
    int helper(vector<int>& cost,vector<int>& vis,int index,int sum)
    {
        if(index>=cost.size())
            return 0;
        if(vis[index]!=0)
            return vis[index];
        int left=helper(cost,vis,index+1,sum);
        int right=helper(cost,vis,index+2,sum);
        int res=cost[index]+min(left,right);
        vis[index]=res;
        return res;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> vis(cost.size(),0);
        return min(helper(cost,vis,0,0),helper(cost,vis,1,0));
    }
};
