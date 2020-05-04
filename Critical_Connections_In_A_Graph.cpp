class Solution {
public:
    vector <vector<int>> res;
    vector<int> adj[555559];
    int timer = 0;
    int in[555555],low[555555],vis[555555] = {0};
    
    void dfs(int s,int par)
    {
        vis[s] = 1;
        in[s] = low[s] = timer++;
        for(int u:adj[s])
        {
            if(u == par) continue;
            if(vis[u] == 1)
            {
                low[s] = min(low[s],in[u]);
            }
            else
            {
                dfs(u,s);
                if(low[u] > in[s])
                {
                    res.push_back({s,u});
                }
                low[s] = min(low[u],low[s]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& conn) {
        int m = conn.size();
        
        for(int i=0;i<m;i++)
        {
            int x,y;
            x = conn[i][0],y = conn[i][1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        dfs(0,-1);
        return res;
    }
};
