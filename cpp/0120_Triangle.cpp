class Solution {
public:
    int res=INT_MAX;
    void helper(vector<vector<int>>& triangle,int i,int j,int n,int r)
    {
        if(i<0 || j<0 || i==n || j==n )
        {
            if(i==n && r<res)
                res=r;
            return;
        }
        r+=triangle[i][j];
        helper(triangle,i+1,j,n,r);
        helper(triangle,i+1,j+1,n,r);
        r-=triangle[i][j];
        return;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        if(n==0)
            return 0;
        helper(triangle,0,0,n,0);

        return res;
        
    }
};


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        if(n==0)
            return 0;
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<i+1;j++)
            {
                triangle[i][j]+=min(triangle[i+1][j],triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
        
    }
};



