class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int far=0;
        for(int i=0;i<n-1;i++)
        {
            far=max(far,i+nums[i]);
            if(far<=i)
                return false;
        }
        return far>=n-1;
    }
};
