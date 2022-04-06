class Solution {
public:
    int res=0;
    void helper(int n, vector<bool>& col, vector<bool>& d1, vector<bool>& d2, int k)
    {
        if(k==n) res++;
        for(int i=0; i<n; i++)
        {
            int id1=i-k+n;
            int id2=k+i;
            if(col[i] || d1[id1] || d2[id2]) continue; 
            
            col[i]=true;
            d1[id1]=true;
            d2[id2]=true;
            helper(n, col, d1, d2, k+1); 
            col[i]=false;
            d1[id1]=false;
            d2[id2]=false;
        }
        
    }
    int totalNQueens(int n) {
        vector<bool> col(n,false), d1(2*n,false),d2(2*n,false);
        helper(n, col, d1, d2, 0);
        return res;
        
    }
};


