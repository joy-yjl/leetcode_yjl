class Solution {
public:

    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>> que;
        int ans=INT_MIN;
        for(int i=0;i<points.size();i++)
        {
            while(!que.empty() && points[i][0]-que.top()[1]>k)
                que.pop();
            if(!que.empty())
                ans=max(ans, points[i][0]+points[i][1]+que.top()[0]);
            que.push({points[i][1]-points[i][0], points[i][0]});
        }
        return ans;
        
        
    }
};
