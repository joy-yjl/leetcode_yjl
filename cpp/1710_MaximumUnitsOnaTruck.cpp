class Solution {
public:
    static bool cmp(const vector<int> &a, const vector<int> &b)
    {
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int res=0;
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        for (int i=0;i<boxTypes.size();i++)
        {
            int num=boxTypes[i][0];
            int weight=boxTypes[i][1];
            if(truckSize>num)
            {
                res+=num*weight;
                truckSize-=num;
            }
            else
            {
                res+=truckSize*weight;
                return res;
            }
        }
        return res;
        
    }
};
