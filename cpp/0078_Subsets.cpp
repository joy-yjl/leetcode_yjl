class Solution {
public:
    void helper(vector<int>& nums,vector<vector<int>>& res,vector<int>& r,int index)
    {
        res.push_back(r);
        if(index==nums.size())
            return;
        for(int i=index;i<nums.size();i++)
        {
            r.push_back(nums[i]);
            helper(nums,res,r,i+1);
            r.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> r;
        helper(nums,res,r,0);
        return res;
    }
};
