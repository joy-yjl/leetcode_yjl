class Solution {
public:
    string addBinary(string a, string b) {
        int m=a.size();
        int n=b.size();
        string res="";
        int tmp=0;
        while(m>0 || n>0 || tmp!=0)
        {
            if(m>0)
            {
                tmp+=(a[m-1]-'0');
            }
            if(n>0)
            {
                tmp+=(b[n-1]-'0');
            }
            res=to_string(tmp%2)+res;
            tmp=tmp/2;
            m--;
            n--;
            
        }
        
        return res;
        
    }
};
