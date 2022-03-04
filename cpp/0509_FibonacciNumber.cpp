class Solution {
public:
    int fib(int n) {
        if(n==0 || n==1)
            return n;
        int a=0,b=1;
        int res=1;
        for(int i=2;i<=n;i++)
        {
            res=a+b;
            a=b;
            b=res;
        }
        return res;
        
    }
};
