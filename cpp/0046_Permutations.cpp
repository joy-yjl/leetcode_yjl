class Solution {
public:
    void helper(vector<int>& nums,int k,vector<int>& visit,vector<vector<int>> &res,vector<int> &r)
    {
        if(k==nums.size())
            res.push_back(r);
        for(int i=0;i<nums.size();i++)
        {
            if(visit[i]==1)
                continue;
            r[k]=nums[i];
            visit[i]=1;
            helper(nums,k+1,visit,res,r);
            visit[i]=0;
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) { 
        int n=nums.size();
        vector<vector<int>> res;
        vector<int> visit(n,0);
        vector<int> r(n,0);
        for(int i=0;i<n;i++)
        {
            r[0]=nums[i];
            visit[i]=1;
            helper(nums,1,visit,res,r);
            visit[i]=0;
            
        }
        return res;
        
    }
};
