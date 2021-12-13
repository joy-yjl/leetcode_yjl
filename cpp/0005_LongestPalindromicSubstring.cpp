/*

动态规划
最外层循环是字符串长度
dp[i][j]=1的条件是 dp[i-1][j+1]=1 && s[i]==s[j]
注意长度为2的情况 初始dp[i-1][j+1]并不为1

时间复杂度和空间复杂度都是 O(n^2)


class Solution {
public:
    string longestPalindrome(string s) {
        int left=0;
        int right=0;
        int n=s.size();
        if (n<2)
            return s;
        vector<vector<int>>  dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
            dp[i][i]=1;
        for(int edge=1;edge<n;edge++)
        {
            for(int i=0,j=i+edge;j<n;i++,j++)
            {
                if(s[i]==s[j])
                {
                    if(edge==1 ||  dp[i+1][j-1]==1)
                    {
                        dp[i][j]=1;
                        left=i;
                        right=j;
                    }
                }

            }

        }
        return s.substr(left,right-left+1);
        
    }
};

*/

/*
中心扩展
为了解决aa这种初始扩展要在字母中间加#

外层循环是字符串的位置 
里层循环是扩展

时间复杂度O(n)

*/

class Solution {
public:
    string longestPalindrome(string s) {
        int left=0;
        int right=0;
        int n=s.size();
        if(n<2)
            return s;
        
        string s_new="#";
        for(int i=0;i<n;i++)
        {
            s_new+=s[i];
            s_new+='#';
        }

        int n_new=s_new.size();
        int length=0;
        for(int i=1;i<n_new;i++)
        {
            for(int j=1;(i-j>=0) && (i+j<n_new);j++)
            {
                if(s_new[i-j]==s_new[i+j])
                {
                    if(((i+j)-(i-j)+1)>length)
                    {
                        left=i-j;
                        right=i+j;
                        length=right-left+1;
                    }
                  

                }
                else 
                    break;
            }
        }
        left=left/2;
        right=right/2-1;
        return s.substr(left,right-left+1);

       
        
    }
};