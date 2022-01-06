class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        res=[]
        self.dfs(res,n,n,'')
        return res

    def dfs(self,res,left,right,out):
        if left>right:
            return
        if left==0 and right ==0:
            res.append(out)
            return
        if left:
            self.dfs(res,left-1,right,out+'(')
        if right:
            self.dfs(res,left,right-1,out+')')


class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        all_res=[['']]
        for i in range(1,n+1):
            tmp=[]
            for j in range(i):
                for k in range(len(all_res[j])):
                    for m in range(len(all_res[i-j-1])):
                        tmp.append('('+all_res[j][k]+')'+all_res[i-j-1][m])
            all_res.append(tmp)

        return all_res[-1]

    
