class Solution {
public:
    bool dfs(vector<int> adj[],vector<int> &col,vector<int>& vis,int s,int c)
    {
        vis[s] = 1;
        col[s] = c;
        for(int u:adj[s])
        {
            if(!vis[u])
            {
                if(dfs(adj,col,vis,u,c^1) == false)
                {
                    return false;
                }
            }
            else
            {
                if(col[s] == col[u])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        if(n == 0)
        {
            return false;
        }
        vector <int> adj[n];
        vector <int> col(n,-1);
        vector <int> vis(n,0);
        int flag = 0;
        for(int i=0;i<n;i++)
        {
            if(graph[i].size() == 0)
            {
                flag = 1;
            }
            for(int j=0;j<graph[i].size();j++)
            {
                adj[i].push_back(graph[i][j]);
            }
        }
        bool ans = true;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                ans &= dfs(adj,col,vis,i,0);
            }
        }
        return ans;
    }
};
