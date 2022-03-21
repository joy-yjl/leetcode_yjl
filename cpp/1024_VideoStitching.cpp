class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if(a[0]==b[0])
            return b[1]<a[1];
        return a[0]<b[0];
    }
    int videoStitching(vector<vector<int>>& clips, int time) {
        int n=clips.size();

        sort(clips.begin(),clips.end(),cmp);

        int start=0;
        int end=0;
        int res=0;
        int i=0;
        while(i < n && clips[i][0] <= start)
        {
            while(i<n &&clips[i][0]<=start )
            {
                end=max(clips[i][1],end);
                i++;
            }
            res++;
            start=end;
            if(end>=time)
                return res;
        }
        
        return -1;

        
    }
};
