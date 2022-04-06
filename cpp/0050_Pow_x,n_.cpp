class Solution {
public:
    double myPow(double x, int n) {
        double res=1.0;
        long nn=n;
        if(nn<0)
        {
            nn=-nn;
            x=1/x;
        }
        if(nn==1)
            return x;
        if(x==1)
            return 1;
        
        long k=1;
        double tmp=x;
        while(nn>1)
        {
            if(k>nn/2)
            {
                nn=nn-k;
                res=res*tmp;
                k=1;
                tmp=x;
                
            }
            tmp=tmp*tmp;
            k=k*2;
        }
        if(nn==0)
            return res;
        else
            return res*x;
            
        
    }
};
