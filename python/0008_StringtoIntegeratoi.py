class Solution(object):
    def myAtoi(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        ls=list(s.strip())
        if len(ls)==0:
            return 0;

        label=-1 if ls[0] == '-' else 1

        if ls[0] in ['-','+']:
            del ls[0]

        res=0
        i=0
        while i<len(ls) and ls[i].isdigit():
            res=res*10+int(ls[i])
            i=i+1

        return max(-2**31, min(label * res,2**31-1))
        

