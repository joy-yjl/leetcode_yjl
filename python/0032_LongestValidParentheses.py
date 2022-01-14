class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        res=0
        stack=[-1]
        for i in range(len(s)):
            if s[i]=='(':
                stack.append(i)
            elif s[i]==')':
                stack.pop()
                if len(stack) ==0:
                    stack.append(i)
                else:
                    res=max(res,i-stack[-1])
        return res

class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        res,left,right=0,0,0
        for i in range(len(s)):
            if s[i]=='(':
                left+=1
            if s[i]==')':
                right+=1
            if left==right:
                res=max(left,res)
            elif right>left:
                left,right=0,0
        left,right=0,0
        for i in list(range(len(s)))[::-1]:
            if s[i]==')':
                left+=1
            if s[i]=='(':
                right+=1
            if left==right:
                res=max(left,res)
            elif right>left:
                left,right=0,0

        return res*2

class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        dp=[0]
        res=0
        for i in range(1,len(s)):
            if s[i]=='(':
                dp.append(0)
            if s[i]==')':
                if s[i-1]=='(':
                    dp.append(dp[i-2]+2 if i-2>=0 else 2)
                elif s[i-1]==')' and dp[i-1]>0 and i-1-dp[i-1]>=0 and s[i-1-dp[i-1]] =='(' :
                    dp.append(dp[i - 1] + dp[i - dp[i - 1] - 2] + 2  if (i - dp[i - 1]) >= 2 else dp[i - 1]+2)
                else：
                    dp.append(0)
            res=max(res,dp[-1])

        return res



