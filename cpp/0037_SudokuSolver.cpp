

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solver(board,0,0);
        
    }
    bool solver(vector<vector<char>>& board,int i,int j)
    {
        if(i==9) return true;
        if(j==9) return solver(board,i+1,0);
        if(board[i][j]!='.') return solver(board,i,j+1);
        for(char c='1';c<='9';c++)
        {
            if(isValid(board,i,j,c))
            {
                board[i][j]=c;

            }
            else
                continue;
            if (solver(board, i, j + 1)) 
                return true;
            board[i][j] = '.';
        }
        return false;


    }
    bool isValid(vector<vector<char>>& board,int i,int j,char c)
    {
        int row = i - i % 3, col = j - j % 3;
        for(int k=0;k<9;k++)
        {
            if(board[i][k]==c )
                return false;
            if(board[k][j]==c )
                return false;
            if(board[k/3+row][k%3+col]==c)
                return false;
        }
        
        return true;

    }
};
