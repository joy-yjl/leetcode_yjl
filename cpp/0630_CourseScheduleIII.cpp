class Solution {
public:
    static bool cmp(const vector<int> & a, const vector<int> &b)
    {
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),cmp);
        priority_queue<int> q;
        int sum=0;
        for(int i=0;i<courses.size();i++)
        {
            sum+=courses[i][0];
            q.push(courses[i][0]);
            if(sum>courses[i][1])
            {
                sum-=q.top();
                q.pop();
                
            }
                
        }
        return q.size();
    }
};
