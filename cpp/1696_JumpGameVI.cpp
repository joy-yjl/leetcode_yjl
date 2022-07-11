class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        vector<int> dp(nums.size(),INT_MIN);
        dp[0]=nums[0];
        priority_queue<pair<int,int>> que;
        que.push({dp[0],0});
        for(int i=1;i<nums.size();i++)
        {
            while(!que.empty() && que.top().second<i-k)
                    que.pop();

                dp[i]=nums[i];
                dp[i]+=(que.empty() ? 0:que.top().first);
                que.push({dp[i], i});
        }
        // for(int i=0;i<nums.size();i++)
        //     cout<<dp[i]<<" "
        // cout<<endl;
        return dp[nums.size()-1];
    }
};
class Solution {
public:
    int helper(vector<int>& nums, vector<int>& vis,int k,int index)
    {
        if(vis[index] != INT_MIN) 
            return vis[index];  

        int res=INT_MIN;
        for(int i=0;i<k && index+i+1<nums.size();i++)
        {
            res=max(res,helper(nums,vis,k,index+i+1)+nums[index]);
        }
        vis[index]=max(res,vis[index]);
        return res;
    }
    int maxResult(vector<int>& nums, int k) {
        vector<int> vis(nums.size(),INT_MIN);
        vis[nums.size()-1]=nums[nums.size()-1];
        return helper(nums,vis,k,0); 
    }
};
