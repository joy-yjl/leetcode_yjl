//滑动窗口，map记录字母出现位置
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> hash;
        int start=0;
        int res=0;
        for(int i=0;i<s.size();i++)
        {
            if(hash.count(s[i])!=0)
            {
                start=start>hash[s[i]]?start:hash[s[i]]+1;
            }
            hash[s[i]]=i;
            res=res>(i-start+1)?res:(i-start+1);
        }
        return res;
        
    }
};
