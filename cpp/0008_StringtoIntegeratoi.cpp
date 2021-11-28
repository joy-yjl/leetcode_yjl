/*
判断好条件就行
*/
class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        long int res=0;
        int flag=0;
        int m=1;
        for(int i=0;i<n;i++)
        {
            if((s[i]<'0'||s[i]>'9') && s[i]!=' ' && s[i]!='+' &&s[i]!='-') 
                break;
            if(s[i]==' ')
            {
                if(flag==1)
                    break;
                else
                    continue;
            }
            else if(s[i]=='-'||s[i]=='+')
            {
                if(flag==1)
                    break;
                else
                {
                    if(s[i]=='-')
                        m=-1;
                    flag=1;
                }
            }
            else
            {
                flag=1;
                res=res*10+(s[i]-48);
                if(m*res>INT_MAX)
                {
                    res=INT_MAX;
                    return res;
                }
                if(m*res<INT_MIN)
                {
                    res=INT_MIN;
                    return res;
                }
                
            }

        }
        return res*m;
        
    }
};
