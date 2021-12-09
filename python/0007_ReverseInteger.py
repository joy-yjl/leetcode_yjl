class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        s=str(abs(x))
        s=s[::-1]
        res=int(s)
        if x<0:
            res=-res
        if res < -(2**31) or res > 2**31 - 1:
            res= 0
    
        return res
        
            
