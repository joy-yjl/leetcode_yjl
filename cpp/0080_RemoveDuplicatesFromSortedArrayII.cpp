class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return n;
        int res=2;
        for(int i=2;i<n;i++)
        {
            if(nums[i]!=nums[res-2])
            {
                nums[res++]=nums[i];
            }
            
        }
        return res;
        
    }
};
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int res=0;
        int label=999999;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==label && count==0)
            {
                nums[res]=nums[i];
                label=nums[i];
                count++;
                res++;
                continue;
            }
            while(i<nums.size() && nums[i]==label && count==1)
                i++;
            if(i>=nums.size())
                break;
            nums[res]=nums[i];
            label=nums[i];
            count=0;
            res++;
            
        }
        return res;
        
    }
};
