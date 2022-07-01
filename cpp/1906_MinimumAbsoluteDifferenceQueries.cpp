class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& q) {
        
        vector<int> temp(101,0);
        vector<vector<int>> hash;
        vector<int>  ans;
        
//         hash i...j number count save .
        for(int i=0;i<nums.size();i++)
        {
            temp[nums[i]]++; 
            hash.push_back(temp);
        }
        
        
        for(int i=0;i<q.size();i++){
            
//             interval number count .
            if(q[i][0]-1<0){
                for(int k=0;k<101;k++)
                  temp[k]=hash[q[i][1]][k];
            }
            else 
            {
                for(int k=0;k<101;k++)
                  temp[k]=hash[q[i][1]][k]-hash[q[i][0]-1][k];
            }
            
//             find number min  ... 
            long x=INT_MIN,m=INT_MAX;
            for(int k=0;k<101;k++) 
                if(temp[k]>0){
                       m=min(m,k-x);
                       x=k;   
                  }
            if(m!=INT_MAX) 
                 ans.push_back(m); 
            else 
                 ans.push_back(-1);
        }
        
        return ans;
        
    }
};


class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n-i;j++)
            {
                int tmp=abs(nums[j]-nums[j+i]);

                if(dp[i-1][j]==0 && dp[i-1][j+1]==0)
                    dp[i][j]=tmp;
                else if(tmp==0 && dp[i-1][j+1]==0)
                    dp[i][j]=dp[i-1][j];
                else if(tmp==0 && dp[i-1][j+1]==0)
                    dp[i][j]=dp[i-1][j];


                else if(dp[i-1][j+1]==0)
                    dp[i][j]=min(dp[i-1][j],tmp);
                else if(dp[i-1][j]==0)
                    dp[i][j]=min(dp[i-1][j+1],tmp);
                else if(tmp==0)
                    dp[i][j]=min(dp[i-1][j+1],dp[i-1][j]);

                else
                    dp[i][j]=min(min(dp[i-1][j],dp[i-1][j+1]),tmp);
            }
        }
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<int> res;
        for(int i=0;i<queries.size();i++)
        {
            int length=abs(queries[i][0]-queries[i][1]);
            if(dp[length][queries[i][0]]==0)
                res.push_back(-1);
            else
                res.push_back(dp[length][queries[i][0]]);
        }
        return res;
        
    }
};
