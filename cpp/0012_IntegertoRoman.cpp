/*
分情况 各种搞if else...
*/
class Solution {
public:
    string intToRoman(int num) {
    	string res="";
    	vector<char> roman{'M', 'D', 'C', 'L', 'X', 'V', 'I'};
        vector<int> value{1000, 500, 100, 50, 10, 5, 1};
        for(int i=0;i<7;i+=2)
        {
        	int tmp=num/value[i];
        	if(tmp<4)
        	{
        		for(int j=0;j<tmp;j++)
        			res=res+roman[i];
        	}
        	else if(tmp==4)
        		res=res+roman[i]+roman[i-1];
        	else if(tmp>4 && tmp<9)
        	{
        		res=res+roman[i-1];
        		for(int j=5;j<tmp;j++)
        			res=res+roman[i];
        	}
        	else
        		res=res+roman[i]+roman[i-2];
        	num=num%value[i];
        }
        return res;
        
    }
};
