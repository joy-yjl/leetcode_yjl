class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()<2)
            return 0;
        int res=0,index=0;
        while(index<nums.size())
        {
            int best_index=-1,best_step=-1;
            if(nums[index]>=(nums.size()-1-index))
            {
                return res+1;
            }
            for(int i=1;i<=nums[index];i++)
            {
                int step=nums[index+i]-(nums[index]-i);
                if(step>best_step)
                {
                    best_step=step;
                    best_index=index+i;
                }
            }
            index=best_index;
    
            res++;
        }
        return res;    
    }
};

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()<2)
            return 0;
        int res=0;
        int end=0,far=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            far=max(far,nums[i]+i);
            if(i==end)
            {
                res++;
                end=far;
            }

        }
        
        return res;    
    }
};
