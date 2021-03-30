//map 和 unordered_map 要怎么用
//

/* 
--map： map内部实现了一个红黑树，该结构具有自动排序的功能，因此map内部的所有元素都是有序的，红黑树的每一个节点都代表着map的一个元素，因此，对于map进行的查找，删除，添加等一系列的操作都相当于是对红黑树进行这样的操作，故红黑树的效率决定了map的效率。
--unordered_map: unordered_map内部实现了一个哈希表，因此其元素的排列顺序是杂乱的，无序的
*/

/*

unordered_map. 4ms 9m
map            8ms 9m

*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> dict;
        vector<int> res;
        for(int i=0;i<nums.size();i++)
        {
            if(dict.count(nums[i]) == 0)
            {
                dict[target-nums[i]]=i;
            }
            else
            {
                res.push_back(i);
                res.push_back(dict[nums[i]]);
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
*/
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
