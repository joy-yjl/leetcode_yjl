class Solution {
public:
    vector<int> grayCode(int n) {
        if(n==0)
            return {0};
        if(n==1)
            return {0,1};

        vector<int> res={0,1};
        int factor=2;
        for(int i=1;i<n;i++)
        {
            for(int j=res.size()-1;j>=0;j--)
            {
                res.push_back(res[j]+factor);
            }
            factor*=2;
        }
        return res;
        
    }
};
