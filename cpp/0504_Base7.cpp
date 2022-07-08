class Solution {
public:
    string convertToBase7(int num) {
        string res="";
        bool flag=false;
        if(num==0)
            return "0";
        if(num<0)
        {
            flag=true;
            num=-num;
        }
        while(num>0)
        {
            int r=num%7;
            num=num/7;
            res=to_string(r)+res;
        }
        return flag?"-"+res:res;
        
    }
};

 


