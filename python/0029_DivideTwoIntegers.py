class Solution(object):
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        flag=(dividend < 0) != (divisor < 0)
        dividend,divisor=abs(dividend),abs(divisor)
        res=0
        while divisor<=dividend:
            d=divisor
            tmp=1
            while (d<<1) < dividend:
                d=d<<1
                tmp=tmp<<1
            res+=tmp
            dividend-=d
        if flag:
            res=res*-1


        return min(max(-2**31, res), 2**31-1)

        
