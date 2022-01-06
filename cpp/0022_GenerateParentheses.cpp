/*
dfs的方法，left表示剩余多少左括号，right表示剩余多少右括号
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(res,n,n,"");
        return res;
        
    }
    void dfs(vector<string> & res,int left,int right,string out)
    {
        if(left==0 && right==0)
        {
            res.push_back(out);
            return;
        }    
        if(left>right) return;
        if(left) dfs(res,left-1,right,out+'(');
        if(right) dfs(res,left,right-1,out+')');

    }
};

/*
动态规划的方法
n个括号的结果是
（p）q
其中p从0到n-1，q从n-1到0 的括号组合
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(1,vector<string> (1,""));
        for(int i=1;i<n+1;i++)
        {
            vector<string> tmp;
            for(int j=0;j<i;j++)
            {
                for(int k=0;k<dp[j].size();k++)
                {
                    for(int m=0;m<dp[i-j-1].size();m++)
                        tmp.push_back('('+dp[j][k]+')'+dp[i-j-1][m]);
                }
            }
            dp.push_back(tmp);
        }
        return dp[n];

        
    }
    
};

