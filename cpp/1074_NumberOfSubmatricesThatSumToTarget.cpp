
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int res=0;

        //vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                matrix[i][j]=matrix[i][j-1]+matrix[i][j];
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=i;j<m;j++)
            {
                unordered_map<int,int> dict{{0,1}};
                int cur=0;
                for(int k=0;k<n;k++)
                {
                    cur += matrix[k][j] - (i > 0 ? matrix[k][i - 1] : 0);
                    res += dict[cur - target];
                    dict[cur]++;
                }

            }
        }
        return res;

    }
};

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+matrix[i-1][j-1];
            }
        }
        int res=0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int p = 1; p <= i; p++) {
                    for (int q = 1; q <= j; q++) {
                        int t = dp[i][j] - dp[i][q - 1] - dp[p - 1][j] + dp[p - 1][q - 1];
                        if (t == target) 
                            res++;
                    }
                }
            }
        }
        return res;        
    }
};
