class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res=0,mid=0;
        int n=nums.size();
        if(n%2==0)
            mid=(nums[n/2]+nums[(n-1)/2])/2;
        else
            mid=nums[n/2];
        for(int i=0;i<n;i++)
            res+=(mid>nums[i]?mid-nums[i]:nums[i]-mid);
        return res;
    }
};
