
/*
用栈记录起始位置
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        int res=0;
        Stack<int> stack;
        stack.push(-1);
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                stack.push(i);
            }
            if(s[i]==')')
            {
                stack.pop();
                if(stacl.empty())
                {
                    stack.push(i);
                }
                else
                {
                    res=max(res,i-stack.top());
                }
            }
        }
        return res;
    }
};
/*
前后各看遍
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        int res=0,left=0,right=0;
        if (s.size()<2)
            return 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                left++;
            }
            if(s[i]==')')
            {
                right++;
            }
            if(left==right)
                res=max(res,right);
            else if(right>left)
            {
                right=0;
                left=0;
            }

        }
        right=0;
        left=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]==')')
            {
                left++;
            }
            if(s[i]=='(')
            {
                right++;
            }
            if(left==right)
                res=max(res,right);
            else if(right>left)
            {
                right=0;
                left=0;
            }

        }
        return res*2;
    }
};

/*
动态规划
碰到)有两种情况 (1)前面是( 只需要判断( 前面是不是完整括号
             （2）前面是 ) 如果前面的)对应是括号 还要看当前的) 有没有(来匹配
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        int res=0;
        vector<int> dp(s.size(),0);
        for(int i=1;i<s.size();i++)
        {
            if(s[i]==')')
            {
                if(s[i-1]=='(')
                {
                    dp[i]=(i>2?dp[i-2]:0)+2;
                }
                else if(dp[i-1]>0 && i-1-dp[i-1]>=0 &&s[i-1-dp[i-1]]=='(')
                {
                    dp[i]=dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                res=max(res,dp[i]);
            }
        }
        return res;
    }
};


