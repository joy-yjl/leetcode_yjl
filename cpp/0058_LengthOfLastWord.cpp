class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        int res =0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]==' ' && res>0)
                return res;
           
            if (s[i]!=' ' )
                res++;            
        }
        return res;
    }
};
