/*
从后往前遍历
存下最大值来判断加还是减
*/
class Solution {
public:
    int romanToInt(string s) {
    	unordered_map<char,int> dict{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    	int res=0;
    	int n=s.size();
    	int max=0;
    	for(int i=n-1;i>=0;i--)
    	{
    		int tmp=dict[s[i]];
    		if(tmp>=max)
    		{
    			res+=tmp;
    			max=tmp;
    		}
    		else
    			res-=tmp;
    	}
        return res;
    }
};
