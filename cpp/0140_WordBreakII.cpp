class Solution {
public:
    void helper(string & s,vector<string>& wordDict,int start,vector<string> &res,string &r)
    {
        if(start==s.size()){
            res.push_back(r);
            return;
        }

        for(int i=0;i<wordDict.size();i++)
        {
            int n=wordDict[i].size();
            if(start+n>s.size())
                continue;
            if(s[start]==wordDict[i][0])
            {
                
                int j=0;
                while(j<n && (j+start)<s.size())
                {
                    if(s[j+start]!=wordDict[i][j])
                        break;
                    j++;
                }
                if(j==n)
                {
                    string rc=r;
                    if(rc=="")
                        rc+=wordDict[i];
                    else
                        rc=rc+" "+wordDict[i];

                    helper(s,wordDict,j+start,res,rc);

     
                }

            }
            
        }

    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        if(s.size()==0 || wordDict.size()==0)
            return res;
        string r="";
        helper(s,wordDict,0,res,r);
      
        return res;

    }
};





