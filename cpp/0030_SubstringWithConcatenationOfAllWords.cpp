
// 30. Substring with Concatenation of All Words
/*
用两个字典来记录 比较词出现的个数
*/
class Solution {
public:
    vector<int> findSubstring(string s,vector<string>& words)
    {
        int n=words.size();
        int len=words[0].size();
        vector<int> res;
        if(s.size()<n*len)
            return res;
        unordered_map<string,int> dict;
        for(int i=0;i<words.size();i++)
        {
              dict[words[i]]+=1;
        }
        for(int i=0;i<=(s.size()-n*len);i++)
        {
            unordered_map<string,int> wd;
            int j=0;
            for(j=0;j<n*len;j+=len)
            {
                string sub=s.substr(i+j,len);
                if(dict.count(sub)==0)
                    break;
                wd[sub]+=1;
                if(wd[sub]>dict[sub]) break;
            }
            if(j==n*len)res.push_back(i);

        }
        return res;
    }
};

/*
还是用两个字典 第一层循环是word的长度
第二层循环一个词一个词的找 每次走word的长度
通过count来比较是不是匹配上了

参考python 滑动窗口 
*/
class Solution {
public:
    vector<int> findSubstring(string s,vector<string>& words)
    {
        int n=words.size();
        int len=words[0].size();
        vector<int> res;
        if(s.size()<n*len)
            return res;
        unordered_map<string,int> dict;
        for(int i=0;i<words.size();i++)
        {
              dict[words[i]]+=1;
        }
        for(int i=0;i<len;i++)
        {
            unordered_map<string,int> wd;
            int count=0;
            int left=i;
            for(int j=i;j<=s.size()-len;j+=len)
            {
                string sub=s.substr(j,len);
                if(dict.count(sub))
                {
                    wd[sub]++;
                    if(wd[sub]<=dict[sub])
                    {
                        count++;
                    }
                    else
                    {
                        while(wd[sub]>dict[sub])
                        {
                            string tmp=s.substr(left,len);
                            wd[tmp]--;
                            if(wd[tmp]<dict[tmp]) count--;
                            left+=len;
                        }
                    }
                    if(count==n)
                    {
                        res.push_back(left);
                        wd[s.substr(left,len)]--;
                        count--;
                        left+=len;
                    }
                } 
                else
                {
                    wd.clear();
                    count=0;
                    left=j+len;
                }
            }
            

        }
        return res;
    }
};
