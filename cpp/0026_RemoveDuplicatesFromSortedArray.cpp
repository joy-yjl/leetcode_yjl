class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int res=0;
        int label=-101;
       
        for(int i=0;i<nums.size();i++)
        {
            while(i<nums.size()&&nums[i]==label)
            {
                 i++;
            }
            if(i>=nums.size())
                break;
             nums[res]=nums[i];
             label=nums[i];
             res++;
            
            
        }
        return res;
        
    }
};
