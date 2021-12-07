#python 字典 判断key在不在字典里 可以用 key in dict, 也可以用 dict.has_key()
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        m_dict={}
        start=-1
        res=0

        for i in range(len(s)):
        	if s[i] in m_dict and start <m_dict[s[i]]:
        		start=m_dict[s[i]]
        	m_dict[s[i]]=i
        	res=max(res,i-start)
        return res
