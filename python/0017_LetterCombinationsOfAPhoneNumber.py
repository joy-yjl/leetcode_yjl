class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """

        if '' == digits: return []
        maps = {
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz'
        }
        ret=['']
        for c in digits:
            tmp=[]
            for y in ret:
                for x in maps[c]:
                    tmp.append(y+x)
            ret=tmp
        
        return ret

    # def letterCombinations(self, digits):
    #     if '' == digits: return []
    #     kvmaps = {
    #         '2': 'abc',
    #         '3': 'def',
    #         '4': 'ghi',
    #         '5': 'jkl',
    #         '6': 'mno',
    #         '7': 'pqrs',
    #         '8': 'tuv',
    #         '9': 'wxyz'
    #     }
    #     return reduce(lambda acc, digit: [x + y for x in acc for y in kvmaps[digit]], digits, [''])

    
