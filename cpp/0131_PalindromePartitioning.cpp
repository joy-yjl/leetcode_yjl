class Solution {
public:
    bool isPalindrome(string s, int start, int end)
    { 
        while(start <= end){
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
    void helper(string &s, int index, vector<string> &r,vector<vector<string>> &res)
    {
        if(index==s.size())
        {
            res.push_back(r);
            return ;
        }
        for(int i=index;i<s.size();i++)
        {
            if(isPalindrome(s, index, i)){ 
                r.push_back(s.substr(index, i - index + 1)); 
                helper(s, i + 1, r, res); 
                r.pop_back(); 
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> r;
        helper(s,0,r,res);
        return res;
    }
};
