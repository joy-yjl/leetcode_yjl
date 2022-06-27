class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> q(target.begin(),target.end()); 
        long long int sum=0;
        for(int i=0;i<target.size();i++)
            sum+=target[i];
        
        while(q.top() != 1)
        {
            int max_n=q.top();
            q.pop();
            sum-=max_n;
            if(max_n<=sum  || sum==0)
                return false;
            int old=max_n%sum;
            if(old==0 && sum!=1)
                return false;
            q.push(old);
            sum+=old;
                
        }
        return true;
    }
};
