class Solution {
public:
    void helper(vector<vector<int>> & graph, vector<vector<int>> & res,vector<int> & vis, int i,int j)
    {
        vis[j]=true;
        for(int k=0;k<graph[j].size();k++)
        {
            if(vis[graph[j][k]])
                continue;
            else
            {
                res[graph[j][k]].push_back(i);
                helper(graph,res,vis,i,graph[j][k]);
            }
        }
    }
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> res(n,vector<int>());
        vector<vector<int>> graph(n,vector<int>());
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
        }
        for(int i=0;i<n;i++)
        {
            vector<int> vis(n,0);
            helper(graph,res,vis,i,i);
        }
        return res; 
    }
};

2192. All Ancestors of a Node in a Directed Acyclic Graph
