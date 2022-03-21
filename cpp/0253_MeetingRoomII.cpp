
class Solution {
public:
    
    int minMeetingRooms(vector<Interval> &intervals) {
        int n=intervals.size();
        vector<int> start,end;
        for(int i=0;i<n;i++)
        {
            start.push_back(intervals[i].start);
            end.push_back(intervals[i].end);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int res=0,count=0,i=0,j=0;
        while(i<n && j<n)
        {
            if(start[i]<end[j])
            {
                count++;
                i++;
            }
            else
            {
                count--;
                j++;
            }
            res=max(res,count);
        }
        return res;
        
        
    }
};
