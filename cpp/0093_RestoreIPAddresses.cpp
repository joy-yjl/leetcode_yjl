class Solution {
public:
    void helper(string & s,int k, int index, vector<string> & res, string r)
    {
        if(k==4 && index==s.size())
            res.push_back(r);
        else
        {
            for (int i= 0; i < 3; i++) {
                if (i+index>=s.size()) 
                    break;
                int val = atoi(s.substr(index, i+1).c_str());
                if (val > 255 || i+1 != to_string(val).size()) 
                    continue;
                helper(s, k + 1, index+i+1 ,res, r + s.substr(index, i+1) + (k == 3 ? "" : "."));
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        helper(s,0,0,res,"");
        return res;
        
    }
};
