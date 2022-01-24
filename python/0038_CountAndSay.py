class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        res='1'
        for i in range(n-1):
            tmp=''
            j=0
            while j<len(res):
                count=1
                while j+1<len(res) and res[j]==res[j+1]:
                    count+=1
                    j+=1
                tmp+=str(count)+res[j]
                j+=1
            res=tmp
        return res


