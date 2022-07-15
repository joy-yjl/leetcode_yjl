class Solution {
public:
    int res=0;
    int  helper(vector<vector<int>>& grid,vector<vector<int>>& vis,int i,int j)
    {
        if(i<0 || i>=grid.size() || j<0 ||j>=grid[0].size())
            return 0;
        if(vis[i][j]==1 || grid[i][j]==0)
            return 0;
        vis[i][j]=1;

        return 1+helper(grid,vis,i-1,j)+helper(grid,vis,i+1,j)+helper(grid,vis,i,j-1)+helper(grid,vis,i,j+1);
        

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int res=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && vis[i][j]==0)
                {
                    
                    int tmp=helper(grid,vis,i,j);
                    res=max(res,tmp);
                }
            }
        }
        return res;
        
    }
};
