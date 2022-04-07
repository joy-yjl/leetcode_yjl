class Solution {
public:
    int mySqrt(int x) {
        if(x==0)
            return 0;
        if(x==1 || x==2 || x==3)
            return 1;
        
        long long left=1, right=x/2, res=0;;
        while(left<=right)
        {
            long long mid=left+(right-left)/2;
            if(mid * mid >x)
            {
                right=mid-1;
            }
            else if(mid*mid <x)
            {
                res=mid;
                left=mid+1;
            }
            else
            {
                return mid;
            }
             // cout<<left<<" "<<right<<endl;
            
        }
        return res;
        
    }
};
