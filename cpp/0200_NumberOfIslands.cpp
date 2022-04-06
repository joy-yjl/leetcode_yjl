class Solution {
public:
    void helper(vector<vector<char>>& grid, int i, int j,vector<vector<int>>& visit)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() ) return;
        if (grid[i][j]=='0' ||visit[i][j]) return;
            
        visit[i][j] = 1;
        helper(grid, i - 1, j, visit);
        helper(grid, i, j - 1, visit);
        helper(grid, i + 1, j, visit);
        helper(grid, i, j + 1, visit);
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        if(n==0)
            return 0;
        
        int m=grid[0].size();
        int res=0;
        vector<vector<int>> visit(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visit[i][j]==1 || grid[i][j]=='0')
                    continue;
                
                if(grid[i][j]=='1')
                {
                    helper(grid,i,j,visit);
                    res++;
                }
            }
        }
        
        return res;
        
    }
};



class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        if(n==0) return 0;
        int m=grid[0].size();
        
        vector<vector<int>> visit(n,vector<int>(m,0));
        int res=0;
        queue<vector<int>> q;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visit[i][j]==0 && grid[i][j]=='1')
                {
                    q.push({i,j});
                    while(!q.empty())
                    {
                        vector<int> tmp=q.front();
                        q.pop();
                        if(tmp[0]<0||tmp[1]<0||tmp[0]>=grid.size()||tmp[1]>=grid[0].size())
                            continue;
                        if(grid[tmp[0]][tmp[1]]=='0' || visit[tmp[0]][tmp[1]]==1) continue;
                        visit[tmp[0]][tmp[1]]=1;
                        q.push({tmp[0]-1,tmp[1]});
                        q.push({tmp[0],tmp[1]-1});
                        q.push({tmp[0]+1,tmp[1]});
                        q.push({tmp[0],tmp[1]+1});
                        
                    }
                    res++;
                }
            }
        }
        return res;
        
    }
};
