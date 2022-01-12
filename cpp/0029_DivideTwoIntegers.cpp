/*
通过按位左移到方式改变除数
每移一位，增大2倍
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        bool flag= (dividend<0 ^ divisor<0);
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        long Dividend = abs(dividend);
        long Divisor = abs(divisor);

        
        long res=0;
        while(Dividend>=Divisor)
        {
            long tmpres=1;
            long d=Divisor;
            while((d<<1)<Dividend)
            {
                d=(d<<1);
                tmpres=(tmpres<<1);
            }
            res+=tmpres;
            Dividend-=d;
        }
        if(flag)res=-res;
        if(res>INT_MAX) return INT_MAX;
        if(res<INT_MIN) return INT_MIN;
        return res;

        
    }
};
