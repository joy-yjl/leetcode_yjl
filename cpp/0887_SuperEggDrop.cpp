
//前两个版本都超时了 第三个版本逆向思维
//第二个版本可以改进，但我不想改了
class Solution {
public:
    int superEggDrop(int k, int n) {
        int res=INT_MAX;
        if(k==1) return n;
        if(n==0) return 0;
        for(int i=1;i<=n;i++)
        {
            res=min(res,max(superEggDrop(k-1,n-i),superEggDrop(k,i-1))+1);
        }
        return res;
        
    }
        
};

class Solution {
public:
    int helper(int k,int n,vector<vector<int>> & dp)
    {
        if(dp[k][n]!=-1)
            return dp[k][n];
        int res=INT_MAX;
        if(k==1) 
        {
            dp[k][n]=n;
            return n;
        }
        if(n==0)
        { 
            dp[k][n]=0;
            return 0;
        }
        for(int i=1;i<=n;i++)
        {
            res=min(res,max(helper(k-1,n-i,dp),helper(k,i-1,dp))+1);
        }
        dp[k][n]=res;
        return res;

    }
    int superEggDrop(int k, int n) {
        vector<vector<int>>  dp(k+1,vector<int>(n+1,-1));
        helper(k,n,dp);
        return dp[k][n];
        
    }
        
};



class Solution {
public:
    int superEggDrop(int k, int n) {
        if (n == 1) {
            return 1;
        }
        vector<vector<int>> f(n + 1, vector<int>(k + 1));
        for (int i = 1; i <= k; ++i) {
            f[1][i] = 1;
        }
        int ans = -1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                f[i][j] = 1 + f[i - 1][j - 1] + f[i - 1][j];
            }
            if (f[i][k] >= n) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};

