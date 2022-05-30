class Solution {
public:
    void helper(vector<vector<char>>& board, int i,int j)
    {
        if(i<0||j<0||i>=board.size()||j>=board[0].size() || board[i][j]=='X' || board[i][j]=='A')
            return;
        else
        {
            board[i][j]='A';
            helper(board,i-1,j);
            helper(board,i,j-1);
            helper(board,i+1,j);
            helper(board,i,j+1);
        }

    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        // vector<int> visit((m+n-2)*2,0);
        for(int i=0;i<m;i++)
        { 
            if( board[i][0]=='X')
                continue;
            else
                helper(board,i,0);
        }
        for(int i=1;i<n;i++)
        { 
            if( board[0][i]=='X')
                continue;
            else
                helper(board,0,i);
        }
        for(int i=1;i<n;i++)
        {
            if(board[m-1][i]=='X')
                continue;
            else
                helper(board,m-1,i);
        }
        for(int i=1;i<m-1;i++)
        {
            if(board[i][n-1]=='X')
                continue;
            else
                helper(board,i,n-1);
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O')
                    board[i][j]='X';
                if(board[i][j]=='A')
                    board[i][j]='O';
            }
        }
        

        
    }
};




