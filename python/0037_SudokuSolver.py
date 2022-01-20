class Solution(object):
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        self.solver(board,0,0)

    def solver(self,board,i,j):
        if i==9:
            return True;
        if j==9:
            return self.solver(board,i+1,0)
        if board[i][j]!='.':
            return self.solver(board,i,j+1)

        for k in range(1,10):
            if not self.isValid(board,i,j,str(k)):
                continue
            board[i][j]=str(k)
            if(self.solver(board,i,j+1)):
                return True
            board[i][j]='.'
        return False        

    def isValid(self,board,i,j,c):
        row,col=i-i%3,j-j%3
        for k in range(9):
            if board[i][k]==c:
                return False
            if board[k][j]==c:
                return False
            if board[row+k/3][col+k%3]==c:
                return False

        return True

