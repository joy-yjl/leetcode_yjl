

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




struct node
{
    int row, col;
    set<int> s{0,1,2,3,4,5,6,7,8};
};
// 放入队列的数据结构

class Solution {
public:
    int solved;
    vector<vector<char>> solvedBoard;

    void solve(vector<vector<char>> board, queue<node*> couldBeSolved, node v[][9]){
        while(!couldBeSolved.empty()){
            auto node = *(couldBeSolved.front());
            if (node.s.size() == 0)
                return;
            // 如果没有唯一解，那么该board无解，回溯
            int row = node.row, col = node.col;
            int sol = *(node.s.begin());
            board[row][col] = sol + '1';
            for (int i = 0; i < 9; ++i)
            {
                // 这个循环是当我们填上唯一解的时候，要对整行整列整个子box去掉解的值
                if (v[row][i].s.find(sol)!=v[row][i].s.end())
                {
                    v[row][i].s.erase(sol);
                    if (board[row][i] == '.' && v[row][i].s.size() == 1){
                        couldBeSolved.push(v[row]+i);
                    }
                }
                if (v[i][col].s.find(sol) != v[i][col].s.end())
                {
                    v[i][col].s.erase(sol);
                    if (board[i][col] == '.' && v[i][col].s.size() == 1){
                        couldBeSolved.push(v[i]+col);
                    }
                }
                int boxIndex = 3*(row/3)+col/3;
                int boxRow = 3*(boxIndex/3)+i/3, boxCol = 3*(boxIndex%3)+i%3;
                if (boxRow != row && boxCol != col && v[boxRow][boxCol].s.find(sol) != v[boxRow][boxCol].s.end())
                {
                    v[boxRow][boxCol].s.erase(sol);
                    if (board[boxRow][boxCol] == '.' && v[boxRow][boxCol].s.size() == 1){
                        couldBeSolved.push(v[boxRow]+boxCol);
                    }
                }
            }
            couldBeSolved.pop();
        }

        int minsize = 10, minrow, mincol;
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
                if (board[i][j] == '.' && v[i][j].s.size() < minsize)
                {
                    minrow = i;
                    mincol = j;
                    minsize = v[i][j].s.size();
                }
        // 找到候选集合最小的那个点
        if (minsize == 0)
        {
            // 无解，返回
            return;
        }
        else if(minsize == 10){
            // 说明没有空格存在了，直接返回
            solved = true;
            solvedBoard = board;
        }
        else{
            for (auto iter = v[minrow][mincol].s.begin(); iter != v[minrow][mincol].s.end(); iter++)
            {
                vector<vector<char>> newBoard = board;
                newBoard[minrow][mincol] = *iter + '1';
                if(solved == false)solveSudoku(newBoard);
                else break;
            }
            // 复制一份board，然后填上一个数字，递归求解
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        node v[9][9];
        solved = false;
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                v[i][j].row = i;
                v[i][j].col = j;
                if (board[i][j] != '.')
                {
                    int num = board[i][j] - '1';
                    for (int k = 0; k < 9; ++k)
                    {
                        v[i][k].s.erase(num);
                        v[k][j].s.erase(num);
                        int boxIndex = 3*(i/3)+j/3;
                        v[3*(boxIndex/3)+k/3][3*(boxIndex%3)+k%3].s.erase(num);
                    }
                }
            }
        }
        // 求解所有的node，node里保存了每个点的位置和候选解
        queue<node*> couldBeSolved;
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
                if(board[i][j] == '.' && v[i][j].s.size() == 1)couldBeSolved.push(v[i]+j);
                else if (board[i][j] == '.' && v[i][j].s.size() == 0)return;
        // 让候选解size为1的点入队列
        solve(board, couldBeSolved, v);
        // 求解
        board = solvedBoard;
    }
};

