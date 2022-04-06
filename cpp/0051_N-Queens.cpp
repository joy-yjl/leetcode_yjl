
class Solution {
public:

    void helper(vector<vector<string>> & res,vector<string> r,int k,int n,vector<bool> &col,vector<bool> &d1,vector<bool> d2)
    {
        if(k==n)
        {
            res.push_back(r);
            return;
        }

        for(int i=0;i<n;i++)
        {
            int id1=n-i+k;
            int id2=k+i;
            if(col[i] || d1[id1] || d2[id2])
                continue;
        
            r[k][i]='Q';
            col[i]=true;
            d1[id1]=true;
            d2[id2]=true;
            helper(res,r,k+1,n,col,d1,d2);
            r[k][i]='.';
            col[i]=false;
            d1[id1]=false;
            d2[id2]=false;
            
            
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        if(n==0 || n==2 || n==3) return res;
        if(n==1) {res.push_back({"Q"}); return res;}
        
        vector<bool> col(n,false);
        vector<bool> d1(2 * n, false);
        vector<bool> d2(2 * n, false);
        
        vector<string> r(n, string(n, '.'));
        
        for(int i=0;i<n;i++)
        {
            r[0][i]='Q';
            col[i]=true;
            d1[n-i]=true;
            d2[i]=true;
            helper(res,r,1,n,col,d1,d2);
            r[0][i]='.';
            col[i]=false;
            d1[n-i]=false;
            d2[i]=false;
            
            
        }
        return res;
        
    }
};






class Solution {
public:
    bool isValid(vector<string>& r, int row, int col) {
        for (int i = 0; i < row; ++i) {
            if (r[i][col] == 'Q') return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (r[i][j] == 'Q') return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < r.size(); --i, ++j) {
            if (r[i][j] == 'Q') return false;
        }
        return true;
    }
    void helper(vector<vector<string>> & res,vector<string> r,int k,int n)
    {
        if(k==n)
        {
            res.push_back(r);
            return;
        }

        for(int i=0;i<n;i++)
        {
            if(isValid(r,k,i))
            {
                r[k][i]='Q';
                helper(res,r,k+1,n);
                r[k][i]='.';
            }
            
           
            
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        if(n==0 || n==2 || n==3) return res;
        if(n==1) {res.push_back({"Q"}); return res;}
        
        vector<string> r(n, string(n, '.'));
        
        for(int i=0;i<n;i++)
        {
            r[0][i]='Q';
            
            helper(res,r,1,n);
            r[0][i]='.';
            
            
        }
        return res;
        
    }
};