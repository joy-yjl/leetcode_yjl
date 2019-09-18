class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows<=1) return s;
        int n=s.size();
        int size=numRows*2-2;
        string res;
        for(int i=0;i<numRows;i++)
        {
            for(int j=i;j<n;j+=size)
            {
                res+=s[j];
                int pose=j+size-i*2;
                if(i!=0&&i!=numRows-1&&pose<n)
                    res+=s[pose];
            }
        }
        return res;
        
        
    }
};
