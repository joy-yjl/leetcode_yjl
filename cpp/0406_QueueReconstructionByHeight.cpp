class Solution {
public:
    static bool cmp(vector<int> &a,vector<int>& b)
    {
        if(a[0]==b[0])
            return a[1]>b[1];
        else
            return a[0]<b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {

        sort(people.begin(),people.end(),cmp);
        vector<vector<int>>  res(people.size(), vector<int>(2,-1));
        for(int i=0;i<people.size();i++)
        {
            int cnt, j;
            for(cnt = 0, j = 0; j < res.size(); j++)
            { 
                if(res[j][1]==-1)
                {
                    if(cnt==people[i][1]) 
                        break;
                    cnt++;
                }
            }
            res[j]=people[i];
        }
        return res;
        
    }
};



