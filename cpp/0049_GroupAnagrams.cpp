class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string,vector<string>> dict;
        int n=strs.size();
        if(n==0)return res;
        if(n==1)
        {
            res.push_back(strs);
            return res;
        }
        for(int i=0;i<n;i++)
        {
            string tmp=strs[i];
            sort(tmp.begin(),tmp.end());
            if(dict.count(tmp))
                dict[tmp].push_back(strs[i]);
            else
                dict[tmp]={strs[i]};
            
        }
        for(auto iter=dict.begin();iter!=dict.end();iter++)
            res.push_back(iter->second);
        return res;
        
        
    }
};
