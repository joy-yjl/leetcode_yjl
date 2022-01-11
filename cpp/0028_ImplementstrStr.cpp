
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "" ) return 0;
        if(haystack.size()<needle.size()) return -1;

        for(int i=0;i<=haystack.size()-needle.size();i++)
        {
            if(haystack[i]==needle[0])
            {
                int j=1;
                for(;j<needle.size();j++)
                {
                    if(haystack[i+j]!=needle[j])
                        break;
                }
                if(j==needle.size())
                    return i;

            }
        }
        return -1;
        
    }
};
