class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        sx=str(x)
        sx_v=sx[::-1]
        if sx==sx_v:
            return True
        else:
            return False
