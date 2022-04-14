class Solution {
public:
    void helper(int index,int n,int k,vector<vector<int>> &res,vector<int> &r)
    {
        if(k==0)
            res.push_back(r);
        if(index>n)
            return;
        for(int i=index;i<=n;i++)
        {
            r.push_back(i);
            helper(i+1,n,k-1,res,r);
            r.pop_back();
        }
        
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> r;
        helper(1,n,k,res,r);
        return res;
        
        
        
    }
};
