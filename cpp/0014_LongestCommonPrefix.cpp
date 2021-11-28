/*
公共前缀 暴力匹配就可以了
及时break
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	int n=strs.size();
    	int min=INT_MAX;
    	string res="";
    	for(int i=0;i<n;i++)
    	{
    		if(min>strs[i].size())
    			min=strs[i].size();
    	}
    	for(int i=0;i<min;i++)
    	{
    		char tmp=strs[0][i];
    		bool flag=true;
    		for(int j=1;j<n;j++)
    		{
    			if(strs[j][i]!=tmp)
    				flag=false;
    		}
    		if(flag)
    			res+=tmp;
    		else
    			break;
    	}
    	return res;
        
    }
};
