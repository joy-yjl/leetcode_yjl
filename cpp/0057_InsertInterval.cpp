class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        vector<vector<int>> res;
        vector<int> r=newInterval;
        for(int i=0;i<n;i++)
        {
            if(intervals[i][1]<r[0])
            {
                res.push_back(intervals[i]);
            }
            else if(intervals[i][0]>r[1])
            {
                res.push_back(r);
                r = intervals[i];
            }
            else
            {
            
                r[0]=min(r[0],intervals[i][0]);
                r[1]=max(r[1],intervals[i][1]);
            }

        }
        res.push_back(r);
        return res;
        
    }
};
