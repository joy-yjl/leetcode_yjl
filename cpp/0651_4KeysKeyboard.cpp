class Solution {
public:
    int maxA(int n) 
    {
        vector<int> dp(n+1,0);
        for (int i = 1; i <= n; i++) {
            // 按 A 键
            dp[i] = dp[i - 1] + 1;
            for (int j = 2; j < i; j++) {
                // 全选 & 复制 dp[j-2]，连续粘贴 i - j 次
                // 屏幕上共 dp[j - 2] * (i - j + 1) 个 A
                dp[i] = max(dp[i], dp[j - 2] * (i - j + 1));
            }
        }
        // N 次按键之后最多有几个 A？
        for(int i=0;i<n+1;i++)
            cout<<dp[i]<<" ";        
        return dp[n];
    }
};
