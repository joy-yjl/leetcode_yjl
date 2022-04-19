
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
            while(i+1<nums.size() && nums[i+1]==nums[i])
                i++;

        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> r;
        sort(nums.begin(),nums.end());
        helper(nums,res,r,0);
        return res;
    }
};
