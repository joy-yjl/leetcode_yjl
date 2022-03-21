class Solution {
public:
    static bool cmp(const vector<int> &a ,const vector<int> &b)
    {
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        if(n==0) return 0;
        if(n==1) return 1;
        sort(points.begin(),points.end(),cmp);
        int res=1;
        int end=points[0][1];
        for(int i=1;i<n;i++)
        {
            if(points[i][0]>end)
            {
                end=points[i][1];
                res++;
            }

        }
        return res;

    }
};
