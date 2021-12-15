/*
先排序，再递归，再用双指针，注意cur vector的处理
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums,int k,int target) {
        vector<vector<int>> res;
        if(nums.empty())
            return res;

        sort(nums.begin(),nums.end());

        vector<int> cur;
        dfs_find(nums,nums.size(),0,target,k,cur,res);

        return res;
    }

    void dfs_find(vector<int> & nums, int len,int start,int target,int k,vector<int> &cur,vector<vector<int>> & res)
    {
        if(target<k*nums.front() || target>k*nums.back())
            return;

        if(k==2)
        {
            int l=start,r=len-1;

            while(l<r)
            {
                int cur_sum=nums[l]+nums[r];

                if(cur_sum==target)
                {
                    cur.push_back(nums[l]);
                    cur.push_back(nums[r]);

                    vector<int> cur_copy(cur);
                    res.push_back(cur_copy);
                    cur.pop_back();
                    cur.pop_back();

                    l++, r--;
                    while(l<r && nums[l]==nums[l-1])
                        l++;
                    while(l<r && nums[r]==nums[r+1])
                        r--;
                }

                else if(cur_sum<target)
                    l++
                else
                    r--
            }

            return;
        }

        for(int i=start;i<=len-k;i++)
        {
            int ele=nums[i];
            if(i>0 && nums[i-1]==ele)
                continue;

            cur.push_back(ele);
            dfs_find(nums,len,i+1,target-ele,k-1,cur,res);
            cur.pop_back();
        }
    }
};
