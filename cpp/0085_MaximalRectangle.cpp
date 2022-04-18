class Solution {
public:
    int helper(vector<int> &v)
    {
        int res=0;
        stack<int> s;
        v.push_back(0);
        for(int i=0;i<v.size();i++)
        {
            while(!s.empty() && v[i]<v[s.top()])
            {
                int top=v[s.top()];
                s.pop();
                int left=s.empty()?-1:s.top();
                res=max(res,top*(i-left-1));

            }
            s.push(i);
        }
        return res;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> v(m,0);

        int res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='1')
                    v[j]++;
                else
                    v[j]=0;
            }
            res=max(res,helper(v));

        }
        return res;
    }
};



