/*
动态规划，比较慢，可以通过单循环解决
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        vector<vector<bool>> dp(m+1,vector<bool> (n+1,false));
        dp[0][0]=true;
        int i=0;
        while(n>i && p[i]=='*')
        {
            dp[0][i+1]=true;
            i++;
        }
        for(i=1;i<m+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(p[j-1]!='*')
                {
                    if( dp[i-1][j-1] && (s[i-1]==p[j-1]|| p[j-1]=='?'))
                        dp[i][j]=true;
                }
                else
                {
                    if(dp[i-1][j-1] || dp[i-1][j] ||dp[i][j-1])
                        dp[i][j]=true;
                }
            }
        }
        return dp[m][n];

        
    }
};
/*
开始进行匹配，若i小于s串的长度，进行 while 循环。若当前两个字符相等，或着p中的字符是问号，则i和j分别加1。
若 p[j] 是星号，要记录星号的位置，jStar 赋为j，此时j再自增1，iStar 赋为i。若当前 p[j] 不是星号，并且不能跟 p[i] 匹配上，此时就要靠星号了，
若之前星号没出现过，那么就直接跪，比如 s = "aa" 和 p = "c*"，此时 s[0] 和 p[0] 无法匹配，虽然 p[1] 是星号，但还是跪。
如果星号之前出现过，可以强行续一波命，比如 s = "aa" 和 p = "*c"，当发现 s[1] 和 p[1] 无法匹配时，但是好在之前 p[0] 出现了星号，
把 s[1] 交给 p[0] 的星号去匹配。至于如何知道之前有没有星号，这时就能看出 iStar 的作用了，因为其初始化为 -1，而遇到星号时，其就会被更新为i，
只要检测 iStar 的值，就能知道是否可以使用星号续命。虽然成功续了命，匹配完了s中的所有字符，但是之后还要检查p串，此时没匹配完的p串里只能剩星号，
不能有其他的字符，将连续的星号过滤掉，如果j不等于p的长度，则返回 false
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0, iStar = -1, jStar = -1, m = s.size(), n = p.size();
        while (i < m) {
            if (j < n && (s[i] == p[j] || p[j] == '?')) {
                ++i; ++j;
            } else if (j < n && p[j] == '*') {
                iStar = i;
                jStar = j++;
            } else if (iStar >= 0) {
                i = ++iStar;
                j = jStar + 1;
            } else return false;
        }
        while (j < n && p[j] == '*') ++j;
        return j == n;
    }
};
