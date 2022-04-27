class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n<2)
            return n;
        int res=1;
        unordered_set<int> num_set(nums.begin(), nums.end());
        for(unordered_set<int>::iterator iter=num_set.begin() ; iter!=num_set.end() ; iter++)
        {
            int tmp=*iter;
            if(num_set.count(tmp-1))
                continue;
            int cur=1;
            while(num_set.count(tmp+1))
            {
                cur++;
                tmp++;
            }
            res=max(res,cur);
        }
        return res;
        
    }
};
//128. Longest Consecutive Sequence

