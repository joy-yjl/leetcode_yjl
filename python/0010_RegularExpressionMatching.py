class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        pre=[True]
        for i in range(len(p)):
            pre.append(p[i]=='*' and i>0 and pre[i-1])

        for i in range(len(s)):
            cur=[False]
            for j in range(len(p)):
                if p[j]!='*':
                    cur.append((s[i]==p[j] or p[j] =='.') and pre[j])
                else:

                    cur.append(cur[j-1] or cur[j] or (pre[j+1] and (s[i]==p[j-1] or p[j-1]=='.')))
            pre=cur
        return cur[-1]

