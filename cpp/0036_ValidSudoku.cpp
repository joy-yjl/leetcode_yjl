

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>>  rowFlag(9,vector<bool>(9));
        vector<vector<bool>>  colFlag(9,vector<bool>(9));
        vector<vector<bool>>  cellFlag(9,vector<bool>(9));
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                    continue;
                int num=board[i][j]-'1';
                if (rowFlag[i][num] || colFlag[j][num] || cellFlag[3 * (i / 3) + j / 3][num]) 
                    return false;
                rowFlag[i][num]=true;
                colFlag[j][num]=true;
                cellFlag[3 * (i / 3) + j / 3][num]=true;

            }
        }
        return true;
        
    }
};

/*
并没有变得更快，内存更少
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       unordered_set<string> set;
       for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                    continue;
                string rowstr=to_string(i)+"("+to_string(board[i][j])+")";
                string colstr="("+to_string(board[i][j])+")"+to_string(j);
                string cellstr=to_string(i/3)+"("+to_string(board[i][j])+")"+to_string(j/3);
                if(set.count(rowstr)||set.count(colstr)||set.count(cellstr))
                    return false;
                set.insert(rowstr);
                set.insert(colstr);
                set.insert(cellstr);

            }
        }
        return true;

        
    }
};
