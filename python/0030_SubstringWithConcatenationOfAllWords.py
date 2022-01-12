class Solution(object):
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        n=len(words)
        size=len(words[0])
        res=[]
        if len(s)<n*size:
            return res

        for i in range(size):
            counter = Counter(words)
            start, end, count = i, i, len(words)
            while(end<len(s)):
                sub=s[end:end+size]
                if sub in counter:
                    counter[sub]-=1;
                    if counter[sub]>=0:
                        count-=1
                end+=size

                if count==0:
                    res.append(start)

                if end-start==n*size:
                    sub=s[start:start+size]
                    if sub in counter:
                        counter[sub]+=1
                        if counter[sub]>0:
                            count+=1
                    start+=size

        return res






