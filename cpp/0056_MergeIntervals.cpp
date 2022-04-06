class Solution {
public:
    static bool cmp(vector<int> &a ,vector<int> &b)
    {
        if(a[0]==b[0])
            return a[1]>b[1];
        return a[0]<b[0];
        
        
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n<2) return intervals;
        sort(intervals.begin(),intervals.end(),cmp);
        
        vector<vector<int>> res;
        vector<int> r=intervals[0];
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]>r[1])
            {
                res.push_back(r);
                r=intervals[i];
            }
            else
            {
                if(intervals[i][1]>r[1])
                    r[1]=intervals[i][1];
            }
            
        }
        res.push_back(r);
        return res;
    }
};
