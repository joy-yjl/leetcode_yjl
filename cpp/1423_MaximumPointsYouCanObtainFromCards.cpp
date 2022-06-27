class Solution {
public:
    int helper(vector<int>& cp,int left,int right,int k,int sum)
    {
        if(k==0 || right<left)
            return sum;
        return max(helper(cp,left+1,right,k-1,sum+cp[left]), helper(cp,left,right-1,k-1,sum+cp[right]));
    }
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int left=0,right=n-1;
        return helper(cardPoints,left,right,k,0);
        
        
    }
};

class Solution {
public:
    int helper(vector<int>& cp,int left,int right,int k,int sum,vector<vector<int>> &visit)
    {
        
        if(k==0 || right<left)
            return sum;
        if(visit[left][right]!=0)
            return visit[left][right];
        sum=max(helper(cp,left+1,right,k-1,sum+cp[left],visit), helper(cp,left,right-1,k-1,sum+cp[right],visit));
        visit[left][right]=sum;
        return sum;
    }
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int left=0,right=n-1;
        vector<vector<int>> visit(n,vector<int>(n,0));
        return helper(cardPoints,left,right,k,0,visit);
    }
};


class Solution {
public:

    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int left=k-1,right=n-1;
        int sum=0,subsum=0;
        for(int i=0;i<n;i++)
        {
            sum+=cardPoints[i];
            if(i>=k)
                subsum+=cardPoints[i];
        }
        int res_=subsum;
        while(left>=0)
        {
            subsum=subsum+cardPoints[left]-cardPoints[right];
            if(res_>subsum)
                res_=subsum;
            left--;
            right--;
        }
        return sum-res_;
        
    }
};
