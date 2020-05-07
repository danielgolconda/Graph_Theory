vector <int> vis(55555);
vector <int> rec(55555);
bool dfs(int s,int par,vector<int> adj[])
{
    vis[s] = 1;
    rec[s] = 1;
    for(int u:adj[s])
    {
        if(!vis[u])
        {
            if(dfs(u,s,adj) == 1)
            {
                return 1;
            }
        }
        else
        {
            if(rec[u] == 1)
            {
                return 1;    
            }
            
        }
    }
    rec[s] = 0;
    return 0;
}

bool isCyclic(int V, vector<int> adj[])
{
    for(int i=0;i<V;i++) vis[i] = 0;
    for(int i=0;i<V;i++) rec[i] = 0;
    for(int i=0;i<V;i++)
    {
        if(vis[i] == 0)
        {
            int x = dfs(i,-1,adj);
            if(x == 1)
            {
                return 1;
            }
        }
    }
    return 0;
}
