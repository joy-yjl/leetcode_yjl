//滑动窗口，map记录字母出现位置
/*
map 12ms
unordered_map 8ms

Start记录起始位置
如果一个字母（如a）又出现了一次 start就从前面的那个（a）后面开始算
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> hash;
        int start=-1;
        int res=0;
        for(int i=0;i<s.size();i++)
        {
            if(hash.count(s[i])!=0)
            {
                start=start>hash[s[i]]?start:hash[s[i]];
            }
            hash[s[i]]=i;
            res=res>(i-start)?res:(i-start);
        }
        return res;
        
    }
};
