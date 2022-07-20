class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int res=0,n=s.size();
        unordered_map<string,int> dict;
        for(int i=0;i<words.size();i++)
            dict[words[i]]++;
        for(unordered_map<string,int>::iterator iter = dict.begin(); iter != dict.end(); ++iter)
        {
            int b1=0,b2=0;
            string s2=iter->first;
            int m=s2.size();
            while(b1<n && b2<m)
            {
                if(s2[b2]==s[b1])
                    b1++,b2++;
                else
                    b1++;
            }
            if(b2==m)
                res+=iter->second;
        }
        return res;
        
    }
};
