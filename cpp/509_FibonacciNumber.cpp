class Solution {
public:
    int fib(int n) {
        if(n==0)
            return 0;
        if(n<3)
            return 1;
        int num1=0,num2=1;
        
        for(int i=1;i<n;i++)
        {
            int tmp=num2;
            num2=num1+num2;
            num1=tmp;
            
        }
        return num2;
        
        
    }
};
