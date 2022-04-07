
class Solution {
public:
    bool isNumber(string S) {
        bool num = false, exp = false, sign = false, dec = false;
        for (auto c : S)
            if (c >= '0' && c <= '9') num = true ;    
            else if (c == 'e' || c == 'E')
                if (exp || !num) return false;
                else exp = true, sign = false, num = false, dec = false;
            else if (c == '+' || c == '-')
                if (sign || num || dec) return false;
                else sign = true;
            else if (c == '.')
                if (dec || exp) return false;
                else dec = true;
            else return false;
        return num;
    }
};

class Solution {
public:
    bool isNumber(string s) {
        int n=s.size();
        bool res=true;
        
        int i=0;
        if(s[0]=='-' || s[0]=='+')
            i++;
        
        bool eflag=false;
        bool pointflag=false;
        bool numflag=false;
        bool numflag2=false;
        while(i<n)
        {
            if(s[i]=='-' || s[i]=='+')
            {
                if(i-1<0 || (s[i-1]!='e' && s[i-1]!='E'))
                {
                    res=false;
                    break;
                }
                
            }
            else if(s[i]!='e' && s[i]!='E'&& s[i]!='.' && (s[i]<'0' || s[i]>'9'))
            {
                res=false;
                break;
            }
            else if(s[i]=='.')
            {
                if (pointflag==false)
                    pointflag=true;
                else
                {
                    res=false;
                    break;
                }
                if(eflag==true)
                {
                    res=false;
                    break;
                }
            }
            else if(s[i]=='e' || s[i]=='E')
            {
                if(numflag==false)
                {
                    res=false;
                    break;
                }
                if(eflag==false)
                    eflag=true;
                else
                {
                    res=false;
                    break;
                }
            }
            else if(s[i]>='0' && s[i]<='9')
            {
                if(numflag==false && eflag==false)
                    numflag=true;
                if(numflag2==false && eflag==true)
                    numflag2=true;
            }
            i++;
            
        }
        if(pointflag==true && numflag==false)
            res=false;
        if(eflag==true && (numflag==false || numflag2==false))
            res=false;
        return res;
        
    }
};
