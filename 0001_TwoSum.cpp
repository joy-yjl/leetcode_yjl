//map 和 unordered_map 要怎么用
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        map<int,int> dict;
        for(int i=0;i<nums.size();i++)
        {
            int temp=dict.count(nums[i]);
            
            if(temp==0)
            {
                dict[target-nums[i]]=i;
            }
            else
            {
                res.push_back(dict[nums[i]]);
                res.push_back(i);
                break;
            }
        }
        return res;
        
        
        
        
    }
};
/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        map<int,int> hash;
        for(int i=0;i<nums.size();i++)
        {
            int tmp=target-nums[i];
            
            if (hash.find(tmp) != hash.end())
            {
                res.push_back(hash[tmp]);
                res.push_back(i);
                return res;
            }
            
            
            hash[nums[i]]=i;
            
        }
        return res;
        
        
    }
};
*/
