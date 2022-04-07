class Solution {
public:
    int climbStairs(int n) {
        if(n==1)
            return 1;
        int a=1,b=1;
        for(int i=1;i<n;i++)
        {
            int tmp=a;
            a=b;
            b=tmp+a;
            
        }
        return b;
        
    }
};
