class Solution {
public:
    int numTrees(int n) {
        vector<int> res(n+1,0);
        res[0]=1;
        res[1]=1;
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                res[i]+=res[j]*res[i-j-1];
            }

        }
        return res[n];

        
    }
};

//超时
class Solution {
public:
    int numTrees(int n) {
        int result=0;
        if(n==1 || n==0)
            return 1;
        for(int i=0;i<n;i++)
            result+=numTrees(i)*numTrees(n-i-1);
        return result;
    }
};
