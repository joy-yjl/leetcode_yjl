class Solution {
public:
    bool dfs(vector<vector<char>> & board,int i,int j,int k,string & word)
    {
        if(k==word.size())
            return true;
        if(i<0 || i>=board.size() || j<0|| j>=board[0].size() ||board[i][j]!=word[k] )
            return false;
            
        board[i][j]='#';
        if (dfs(board,i-1,j,k+1,word) ){ board[i][j]=word[k];return true;}
        if (dfs(board,i,j-1,k+1,word) ){ board[i][j]=word[k];return true;}
        if (dfs(board,i+1,j,k+1,word) ){ board[i][j]=word[k];return true;}
        if (dfs(board,i,j+1,k+1,word) ){ board[i][j]=word[k];return true;}
        board[i][j]=word[k];
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        int l=word.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                   
                    if(dfs(board,i,j,0,word))
                        return true;
                }
            }
        }
        return false;
        
    }
};