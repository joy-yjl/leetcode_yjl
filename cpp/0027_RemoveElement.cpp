class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int res=0;
        int label=-1;
       
        for(int i=0;i<nums.size();i++)
        {
            while(i<nums.size()&&nums[i]==val)
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


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
            nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
        return nums.size();
    }
};
