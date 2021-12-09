/*
判断好条件就行
*/
/*
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
 */

class Solution {
public:
    int myAtoi(string str) {
        int i=0;
        long long int res=0;
        while(str[i]==' ')
            i++;
        int flag=1;
        if(str[i]=='-'||str[i]=='+')
        {
            if(str[i]=='-')
                flag=-1;
            i++;
        }

        for(;i<str.size();i++)
        {
            if(str[i]<'0' || str[i]>'9')
                break;
            res=res*10+(str[i]-'0');
            if (res*flag>INT_MAX||res*flag<INT_MIN)
                break;
        }
        //cout<<res<<endl;
        res=res*flag;
        if(res>INT_MAX)
            res=INT_MAX;
        if(res<INT_MIN)
            res=INT_MIN;

        return res;


    }
};
