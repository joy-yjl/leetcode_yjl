/*
通过dfs递归实现
*/
class Solution {
public:
    unordered_map<char,string> dict{{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size()==0)return res;
        dfs(res,digits,0,"");
        return res;

        
    }
    void dfs(vector<string> & res,string & digits,int pos,string s)
    {
        if(pos==digits.size()) res.push_back(s);
        else
        {
            for(int i=0;i<dict[digits[pos]].size();i++)
            {
                dfs(res,digits,pos+1,s+dict[digits[pos]][i]);
            }
        }
    }
};


