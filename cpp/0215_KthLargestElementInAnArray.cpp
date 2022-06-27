class Solution {
public:
    int helper(vector<int>& nums, int left, int right)
    {
        int mid=nums[left];
        int l=left+1,r=right;
        while(l<=r)
        {
            if (nums[l] < mid && nums[r] > mid) {
                swap(nums[l++], nums[r--]);
            }
            if (nums[l] >= mid) ++l;
            if (nums[r] <= mid) --r;
        }
        swap(nums[left],nums[r]);
        return r;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int left=0,right=nums.size()-1;
        while(right>=left)
        {
            int pos=helper(nums,left,right);
            if(pos==k-1) return nums[pos];
            else if(pos>k-1) right=pos-1;
            else left=pos+1;
        }
        return 0;
        
    }
};
