#这个版本慢了
class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
    
        seen = []
        for i, row in enumerate(board):
            for j, c in enumerate(row):
                if c != '.':
                    seen += [(c,j),(i,c),(i/3,j/3,c)]
        return len(seen) == len(set(seen))

#这个版本更快
class Solution(object):    
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        big = set()
        for i in xrange(0,9):
            for j in xrange(0,9):
                if board[i][j]!='.':
                    cur = board[i][j]
                    if (i,cur) in big or (cur,j) in big or (i/3,j/3,cur) in big:
                        return False
                    big.add((i,cur))
                    big.add((cur,j))
                    big.add((i/3,j/3,cur))
        return True
