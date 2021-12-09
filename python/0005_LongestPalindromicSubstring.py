class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        res=""
        for i in range(len(s)):
            tmp=self.helper(s,i,i)
            if len(tmp)>len(res):
                res=tmp

            tmp=self.helper(s,i,i+1)
            if len(tmp)>len(res):
                res=tmp
        return res


    def helper(self,s,left,right):
        while left >= 0 and right < len(s) and s[left]==s[right]:
            left=left-1
            right=right+1
        return s[left+1:right]


