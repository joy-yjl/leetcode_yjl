class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        int cur=0;
        while(cur<=right)
        {
            if(nums[cur]==0 && cur!=left)
            {
                nums[cur]=nums[left];
                nums[left]=0;
                left++;
                
                
            }
            else if(nums[cur]==2 && cur!=right)
            {
                nums[cur]=nums[right];
                nums[right]=2;
                right--;
                
            }
            else
                cur++;
        }
        
    }
};
