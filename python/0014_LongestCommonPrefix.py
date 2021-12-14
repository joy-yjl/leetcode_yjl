
'''
这个题目中给的字符串列表是这样的：

["flower","flow","flight"]
1
如果我们把它看作是压缩后的结果，也就是说，

(a[0], b[0], c[0], d[0], e[0], f[0]) == ('f', 'l', 'o', 'w', 'e', 'r')
(a[1], b[1], c[1], d[1]) == ('f', 'l', 'o', 'w')
(a[2], b[2], c[2], d[2], e[2], f[2]) == ('f', 'l', 'i', 'g', 'h', 't')
1
2
3
那么，如果我们将它们进行解压，得到的结果就应该是这样的：

a = ['f', 'f', 'f']
b = ['l', 'l', 'l']
c = ['o', 'o', 'i']
d = ['w', 'w', 'g']
# 没有e和f，因为压缩是按最短来的，解压也一样，上面只是为了方便说明

'''

class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        
        res=''
        ll=list(zip(*strs))
        for l in ll:
            if len(set(l))==1:
                res+=l[0]
            else:
                break
        return res
