class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int sum=0;
        int res=0,minsum=0;
        for(int i=0;i<n;i++)
        {
            sum+=(gas[i]-cost[i]);
            if(sum<minsum)
            {
                res=i+1;
                minsum=sum;
            }
        }
        if(sum<0)
            return -1;
        return res%n;

        
    }
};
