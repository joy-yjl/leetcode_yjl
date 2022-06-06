class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        if(n<2)
            return n;
        vector<int> num(n,1);
        for(int i=1;i<n;i++)
        {
            if(ratings[i]>ratings[i-1])
                num[i]=num[i-1]+1;
        }
        for(int i=n-1;i>0;i--)
        {
            if(ratings[i-1]>ratings[i])
                num[i-1]=max(num[i]+1,num[i-1]);
        }
        int res=0;
        for(int i=0;i<n;i++)
            res+=num[i];

        return res;

        
    }
};


class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        if(n<2)
            return n;
        int res=1, pre=1,count=0;

        for(int i=1;i<n;i++)
        {
            if(ratings[i]<ratings[i-1])
                count++;
            else 
            {
                if(count!=0)
                {
                    res+=(1+count)*count/2;
                    if (count >= pre) res += count - pre + 1;
                    count=0;
                    pre=1;
                }
                pre=(ratings[i] == ratings[i - 1]) ? 1 : pre + 1;
                res+=pre;

            }
            
        }
        if(count>0)
        {
            res+=(1+count)*count/2;
            if (count >= pre) res += count - pre + 1;
        }
        return res;
        
    }
};
