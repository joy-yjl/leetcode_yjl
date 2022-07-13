class Solution {
public:
    int maximum69Number (int num) {
        int res=0;
        bool flag=0;
        int i=1000;
        while(num)
        {
            int tmp=num/i;
            num = num%i;
            i=i/10;
            if(tmp==6 && flag==0)
            {
                tmp=9;
                flag=1;
            }
            // cout<<res<<endl;
            res=res*10+tmp;
        }
        
        return res;
    }
};
