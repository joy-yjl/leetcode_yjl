/*
注意边界值的处理，也就是res大于最大的int可表示的数时，返回0
*/

Solution {
public:
    int reverse(int x) {
        if(x<10&&x>-10)
            return x;
        long int res=0;
        while(x)
        {
            int flag=x%10;
            res=res*10+flag;
            if(res<INT_MIN || res>INT_MAX)
                return 0;
            x=x/10;


        }
        return res;
    }
};
